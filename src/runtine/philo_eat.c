/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:34:44 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/04 12:12:06 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	take_forks(t_philo *philo);
static void		down_forks(t_philo *philo);
static t_bool	picked_up(t_philo *philo, pthread_mutex_t *fork);

t_bool	philo_eat(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	if (philo->satisfied)
		return (FALSE);
	if (!take_forks(philo))
		return (FALSE);
	pthread_mutex_lock(&philo->meal);
	philo->last_meal = get_timestamp();
	philo->meals++;
	pthread_mutex_unlock(&philo->meal);
	psafe(philo, EATING);
	wait_ms(table, table->time_to_eat);
	down_forks(philo);
	if (table->limit_meals != -1 && philo->meals >= table->limit_meals)
	{
		pthread_mutex_lock(&philo->meal);
		philo->satisfied = TRUE;
		pthread_mutex_unlock(&philo->meal);
	}
	return (TRUE);
}

static t_bool	take_forks(t_philo *philo)
{
	if (should_stop(philo->table))
		return (FALSE);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		psafe(philo, TAKE_FORK);
		if (!picked_up(philo, philo->right_fork))
			return (FALSE);
		pthread_mutex_lock(philo->left_fork);
		psafe(philo, TAKE_FORK);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		psafe(philo, TAKE_FORK);
		if (!picked_up(philo, philo->left_fork))
			return (FALSE);
		pthread_mutex_lock(philo->right_fork);
		psafe(philo, TAKE_FORK);
	}
	return (TRUE);
}

static void	down_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}

static t_bool	picked_up(t_philo *philo, pthread_mutex_t *fork)
{
	if (should_stop(philo->table))
	{
		pthread_mutex_unlock(fork);
		return (FALSE);
	}
	return (TRUE);
}
