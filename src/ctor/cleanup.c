/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 00:09:03 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/04 08:51:17 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_forks(t_table *table);
static void	destroy_philos(t_table *table);

void	cleanup(t_table *table)
{
	destroy_forks(table);
	destroy_philos(table);
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->state);
}

static void	destroy_forks(t_table *table)
{
	size_t			i;
	pthread_mutex_t	*forks;

	i = 0;
	forks = table->forks;
	while (i < (size_t)table->members)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(forks);
	table->forks = NULL;
}

static void	destroy_philos(t_table *table)
{
	size_t	i;
	t_philo	*philos;

	i = 0;
	philos = table->philos;
	while (i < (size_t)table->members)
	{
		pthread_mutex_destroy(&philos[i].meal);
		i++;
	}
	free(philos);
	table->philos = NULL;
}
