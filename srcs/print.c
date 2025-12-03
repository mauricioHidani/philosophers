/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:28:36 by mhidani           #+#    #+#             */
/*   Updated: 2025/12/03 16:51:03 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_status(t_philo *philo, char *status)
{
	long	timestamp;

	pthread_mutex_lock(&philo->table->lifetime_mtx);
	if (philo->table->someone_died)
	{
		pthread_mutex_unlock(&philo->table->lifetime_mtx);
		return ;
	}
	pthread_mutex_unlock(&philo->table->lifetime_mtx);
	pthread_mutex_lock(&philo->table->print_mtx);
	timestamp = ft_get_time() - philo->table->lifetime;
	printf("🛸 Philospher %d : %s [%ldms]\n", philo->id, status, timestamp);
	pthread_mutex_unlock(&philo->table->print_mtx);
}

void	ft_print_unverified(t_philo *philo, char *status)
{
	long	timestamp;

	pthread_mutex_lock(&philo->table->print_mtx);
	timestamp = ft_get_time() - philo->table->lifetime;
	printf("🛸 Philospher %d : %s [%ldms]\n", philo->id, status, timestamp);
	pthread_mutex_unlock(&philo->table->print_mtx);
}
