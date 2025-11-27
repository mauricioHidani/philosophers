/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:52:37 by mhidani           #+#    #+#             */
/*   Updated: 2025/11/27 17:00:02 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_think(t_table *table)
{
	struct timeval	start;
	struct timeval	crr;
	time_t			end;

	gettimeofday(&start, NULL);
	end = start.tv_sec + (table->starvation_time * 1000);
	while (crr.tv_usec < end)
	{
		pthread_mutex_lock(&(table->meal_mtx));
		// modificar estado de garfos
		pthread_mutex_unlock(&(table->meal_mtx));
		usleep(200);
		gettimeofday(&crr, NULL);
	}
}
