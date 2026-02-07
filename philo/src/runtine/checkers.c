/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:53:46 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/07 14:22:05 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	should_stop(t_table *table)
{
	t_bool	stop;

	stop = FALSE;
	pthread_mutex_lock(&table->death);
	stop = table->stop;
	pthread_mutex_unlock(&table->death);
	return (stop);
}

t_bool	check_deaths(t_table *table)
{
	long	i;
	long	last_meal;
	t_philo	*philos;

	i = 0;
	philos = table->philos;
	while (i < table->members)
	{
		pthread_mutex_lock(&philos[i].serving);
		last_meal = timestamp() - philos[i].last_meal - 1;
		pthread_mutex_unlock(&philos[i].serving);
		if (last_meal >= table->time_to_die)
		{
			psafe(&philos[i], DIE);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

t_bool	check_satisfaction(t_table *table)
{
	long	i;
	long	meals;
	long	satisfied;
	t_philo	*philos;

	if (table->limit_meals == -1)
		return (FALSE);
	i = 0;
	satisfied = 0;
	philos = table->philos;
	while (i < table->members)
	{
		pthread_mutex_lock(&philos[i].meal);
		meals = philos[i].meals;
		pthread_mutex_unlock(&philos[i].meal);
		if (meals >= table->limit_meals)
			satisfied++;
		i++;
	}
	if (satisfied == table->members)
		return (TRUE);
	return (FALSE);
}
