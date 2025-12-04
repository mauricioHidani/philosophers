/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:22:39 by mhidani           #+#    #+#             */
/*   Updated: 2025/12/04 01:23:40 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_dining_table_monitor(t_dining_table *table)
{
	size_t i;
	t_philo *philo;

	i = 0;
	while (i < (size_t)table->number_of_philos)
	{
		philo = table->philos[i];
		if (pthread_create(&philo->thread, NULL, ft_routine_monitor, philo) != 0)
			return;
		i++;
	}
	if (pthread_create(&table->death_monitor, NULL,
						ft_death_monitor, table) != 0)
		return;
	i = 0;
	while (i < (size_t)table->number_of_philos)
	{
		philo = table->philos[i];
		if (pthread_join(philo->thread, NULL) != 0)
			return;
		i++;
	}
	if (pthread_join(table->death_monitor, NULL) != 0)
		return;
}

void *ft_routine_monitor(void *ptr)
{
	t_philo *philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		ft_wait_for_time(philo->table->time_to_eat * 0.5);
	while (TRUE)
	{
		pthread_mutex_lock(&philo->table->lifetime_mtx);
		if (philo->table->someone_died)
		{
			pthread_mutex_unlock(&philo->table->lifetime_mtx);
			break;
		}
		pthread_mutex_unlock(&philo->table->lifetime_mtx);
		if (philo->table->number_of_meals > 0 &&
			philo->meals_eaten >= philo->table->number_of_meals)
			break;
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}

void *ft_death_monitor(void *ptr)
{
	t_dining_table *table;
	long time_since;
	size_t i;

	table = (t_dining_table *)ptr;
	ft_wait_for_time(table->time_to_die / 2);
	while (TRUE)
	{
		i = 0;
		while (i < (size_t)table->number_of_philos)
		{
			time_since = ft_get_time() - table->philos[i]->last_meal;
			if (time_since > table->time_to_die)
			{
				pthread_mutex_lock(&table->lifetime_mtx);
				table->someone_died = TRUE;
				pthread_mutex_unlock(&table->lifetime_mtx);
				ft_print_unverified(table->philos[i], "😵 dead");
				return (NULL);
			}
			i++;
		}
		ft_wait_for_time(200);
	}
	return (NULL);
}
