/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:37:34 by mhidani           #+#    #+#             */
/*   Updated: 2025/12/04 01:27:29 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
	}
	ft_print_status(philo, "🍴 has taken forks");
	ft_print_status(philo, "🍝 eating");
	philo->last_meal = ft_get_time();
	ft_wait_for_time(philo->table->time_to_eat);
	philo->meals_eaten += 1;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	ft_sleep(t_philo *philo)
{
	ft_print_status(philo, "😴 sleeping");
	ft_wait_for_time(philo->table->time_to_sleep);
}

void	ft_think(t_philo *philo)
{
	long	time_to_think;
	long	time_to_eat;
	long	time_to_sleep;
	long	time_to_die;

	time_to_eat = philo->table->time_to_eat;
	time_to_die = philo->table->time_to_die;
	time_to_sleep = philo->table->time_to_sleep;
	time_to_think = (time_to_die - time_to_sleep - time_to_eat) / 2;
	ft_print_status(philo, "🤔 thinking");
	if (time_to_think > 0 && time_to_think < 600)
		ft_wait_for_time(time_to_think);
	else if (time_to_think > 600)
		ft_wait_for_time(1);
}
