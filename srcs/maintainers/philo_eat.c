/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:00:23 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/31 15:00:06 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, MSG_TAKE_FORK);
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, MSG_TAKE_FORK);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, MSG_TAKE_FORK);
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, MSG_TAKE_FORK);
	}
	pthread_mutex_lock(&philo->table->death_mtx);
	philo->last_meal = get_timestamp_ms();
	pthread_mutex_unlock(&philo->table->death_mtx);
	print_action(philo, MSG_EATING);
	sleep_for(philo->table->time_to_sleep, philo->table->is_finished);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	philo->meals++;
}
