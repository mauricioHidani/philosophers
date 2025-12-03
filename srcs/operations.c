/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:37:34 by mhidani           #+#    #+#             */
/*   Updated: 2025/12/02 22:48:28 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	if (philo->id %2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
	}

	ft_print_status(philo, "🚩 has taken forks");
	ft_print_status(philo, "🍝 eating");
	philo->last_meal = ft_get_time();
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
	ft_print_status(philo, "🤔 thinking");
}
