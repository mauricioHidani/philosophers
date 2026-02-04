/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_runtine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:52:53 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/04 11:29:37 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	check_died(t_philo *philo);
static t_bool	check_satisfied(t_table *table, long satisfied);
static void		acc_satisfied(t_philo *philo, long *satisfied);

void	*monitor_runtine(void *arg)
{
	t_table	*table;
	long	i;
	long	satisfied;

	if (!arg)
		return (NULL);
	table = (t_table *)arg;
	while (!should_stop(table))
	{
		i = 0;
		satisfied = 0;
		while (i < table->members)
		{
			if (check_died(&table->philos[i]))
				return (NULL);
			acc_satisfied(&table->philos[i], &satisfied);
			i++;
		}
		if (check_satisfied(table, satisfied))
			return (NULL);
		usleep(1e3);
	}
	return (NULL);
}

static t_bool	check_died(t_philo *philo)
{
	t_table	*table;
	long	last_meal;

	table = philo->table;
	pthread_mutex_lock(&philo->meal);
	last_meal = get_timestamp() - philo->last_meal;
	pthread_mutex_unlock(&philo->meal);
	if (last_meal >= table->time_to_die)
	{
		pthread_mutex_lock(&table->state);
		table->finished = TRUE;
		pthread_mutex_unlock(&table->state);
		psafe(philo, DIED);
		return (TRUE);
	}
	return (FALSE);
}

static t_bool	check_satisfied(t_table *table, long satisfied)
{
	if (satisfied >= table->members)
	{
		pthread_mutex_lock(&table->state);
		table->finished = TRUE;
		pthread_mutex_unlock(&table->state);
		return (TRUE);
	}
	return (FALSE);
}

static void	acc_satisfied(t_philo *philo, long *satisfied)
{
	pthread_mutex_lock(&philo->meal);
	if (philo->satisfied)
	{
		(*satisfied)++;
		pthread_mutex_unlock(&philo->meal);
	}
	pthread_mutex_unlock(&philo->meal);
}
