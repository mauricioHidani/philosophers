/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_runtine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 21:41:41 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/07 14:16:32 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	peat(t_philo *philo);
static t_bool	psleep(t_philo *philo);
static t_bool	pthink(t_philo *philo);

void	*philo_runtine(void *arg)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)arg;
	table = philo->table;
	if (table->members == 1)
	{
		psafe(philo, TAKE_FORK);
		wait_time(table, table->time_to_die);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep(500);
	while (!should_stop(table))
	{
		if (!peat(philo))
			break ;
		if (!psleep(philo))
			break ;
		if (!pthink(philo))
			break ;
	}
	return (NULL);
}

static t_bool	peat(t_philo *philo)
{
	int		first;
	int		second;
	t_table	*table;

	table = philo->table;
	if (should_stop(table))
		return (FALSE);
	find_forks(philo, &first, &second);
	if (!take_forks(philo, first, second))
		return (FALSE);
	psafe(philo, EAT);
	pthread_mutex_lock(&philo->serving);
	philo->last_meal = timestamp();
	pthread_mutex_unlock(&philo->serving);
	pthread_mutex_lock(&philo->meal);
	philo->meals++;
	pthread_mutex_unlock(&philo->meal);
	wait_time(table, table->time_to_eat);
	if (!down_forks(philo, first, second))
		return (FALSE);
	return (TRUE);
}

static t_bool	psleep(t_philo *philo)
{
	if (should_stop(philo->table))
		return (FALSE);
	psafe(philo, SLEEP);
	wait_time(philo->table, philo->table->time_to_sleep);
	return (TRUE);
}

static t_bool	pthink(t_philo *philo)
{
	if (should_stop(philo->table))
		return (FALSE);
	psafe(philo, THINK);
	return (TRUE);
}
