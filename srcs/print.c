/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:28:36 by mhidani           #+#    #+#             */
/*   Updated: 2025/12/05 16:26:12 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_print_locked(t_philo *philo, char *status);

void	ft_print_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->table->lifetime_mtx);
	if (philo->table->someone_died)
	{
		pthread_mutex_unlock(&philo->table->lifetime_mtx);
		return ;
	}
	pthread_mutex_unlock(&philo->table->lifetime_mtx);
	ft_print_locked(philo, status);
}

void	ft_print_locked(t_philo *philo, char *status)
{
	long	timestamp;

	pthread_mutex_lock(&philo->table->print_mtx);
	timestamp = ft_get_time() - philo->table->lifetime;
	printf("[%ldms] [🛸 Philospher %d] [%s]\n", timestamp, philo->id, status);
	pthread_mutex_unlock(&philo->table->print_mtx);
}
