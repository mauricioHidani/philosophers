/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:36:46 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/04 23:00:49 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo			*init_philos(t_table *table);
static pthread_mutex_t	*init_forks(t_table *table);

void	init_table(t_table *table, char **args)
{
	table->members = ft_atol(args[1]);
	table->start_time = 0;
	table->time_to_die = ft_atol(args[2]);
	table->time_to_eat = ft_atol(args[3]);
	table->time_to_sleep = ft_atol(args[4]);
	table->limit_meals = -1;
	if (args[5])
		table->limit_meals = ft_atol(args[5]);
	table->philos = init_philos(table);
	table->forks = init_forks(table);
	pthread_mutex_init(&table->print, NULL);
	pthread_mutex_init(&table->death, NULL);
	pthread_mutex_init(&table->servings, NULL);
	table->stop = FALSE;
}

static t_philo	*init_philos(t_table *table)
{
	t_philo	*philos;
	long	i;

	i = 0;
	philos = malloc(table->members * sizeof(t_philo));
	if (!philos)
		return (NULL);
	while (i < table->members)
	{
		philos[i].id = i + 1;
		philos[i].last_meal = 0;
		philos[i].table = table;
		pthread_mutex_init(&philos[i].meal, NULL);
		pthread_mutex_init(&philos[i].serving, NULL);
		i++;
	}
	return (philos);
}

static pthread_mutex_t	*init_forks(t_table *table)
{
	pthread_mutex_t	*forks;
	long			i;

	i = 0;
	forks = malloc(table->members * sizeof(pthread_mutex_t));
	if (!forks)
		return (NULL);
	while (i < table->members)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

