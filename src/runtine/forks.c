/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 09:45:15 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/05 09:54:41 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	find_forks(t_philo *philo, int *first, int *second)
{
	if (philo->id % 2 == 0)
	{
		*first = philo->id - 1;
		*second = philo->id % philo->table->members;
	}
	else
	{
		*first = philo->id % philo->table->members;
		*second = philo->id - 1;
	}
}

t_bool	take_forks(t_philo *philo, int first, int second)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_lock(table->forks + first);
	if (should_stop(table))
	{
		pthread_mutex_unlock(table->forks + first);
		return (FALSE);
	}
	psafe(philo, TAKE_FORK);
	pthread_mutex_lock(table->forks + second);
	psafe(philo, TAKE_FORK);
	return (TRUE);
}

t_bool	down_forks(t_philo *philo, int first, int second)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_unlock(table->forks + first);
	pthread_mutex_unlock(table->forks + second);
	return (TRUE);
}
