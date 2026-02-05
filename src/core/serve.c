/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:50:32 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/04 22:59:24 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	serve_meal(t_table *table)
{
	long	i;
	t_philo	*philos;

	i = 0;
	philos = table->philos;
	table->start_time = timestamp();
	i = 0;
	while (i < table->members)
	{
		pthread_mutex_lock(&philos[i].meal);
		philos[i].last_meal = table->start_time;
		pthread_mutex_unlock(&philos[i].meal);
		pthread_create(&philos[i].thread, NULL, philo_runtine, &philos[i]);
		i++;
	}
	pthread_create(&table->thread, NULL, monitor_runtine, table);
}

void	wait_threads(t_table *table)
{
	long	i;
	t_philo	*philos;

	i = 0;
	philos = table->philos;
	while (i < table->members)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	pthread_join(table->thread, NULL);
}
