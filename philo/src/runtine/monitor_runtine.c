/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_runtine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 21:44:40 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/04 23:05:30 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	stop_simulation(t_table *table);

void	*monitor_runtine(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	while (!should_stop(table))
	{
		if (check_deaths(table))
		{
			stop_simulation(table);
			break ;
		}
		if (check_satisfaction(table))
		{
			stop_simulation(table);
			break ;
		}
		usleep(500);
	}
	return (NULL);
}

static void	stop_simulation(t_table *table)
{
	pthread_mutex_lock(&table->death);
	table->stop = TRUE;
	pthread_mutex_unlock(&table->death);
}
