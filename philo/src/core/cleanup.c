/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:48:38 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/04 21:53:34 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_mutexes(t_table *table);

void	cleanup(t_table *table)
{
	destroy_mutexes(table);
	free(table->forks);
	free(table->philos);
}

static void	destroy_mutexes(t_table *table)
{
	long			i;
	pthread_mutex_t	*forks;
	t_philo			*philos;

	i = 0;
	forks = table->forks;
	while (i < table->members)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	i = 0;
	philos = table->philos;
	while (i < table->members)
	{
		pthread_mutex_destroy(&philos[i].meal);
		pthread_mutex_destroy(&philos[i].serving);
		i++;
	}
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->death);
	pthread_mutex_destroy(&table->servings);
}
