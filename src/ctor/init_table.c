/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:21:28 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/03 23:46:53 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void				set_input_at(char **in, t_table *table);
static pthread_mutex_t	*new_forks(t_table *table);
static t_philo			*new_philos(t_table *table);
static t_philo			*init_philo_mtx(t_philo *philos, size_t idx);

t_bool	init_table(char **in, t_table *table)
{
	size_t	i;

	set_input_at(in, table);
	table->start = 0;
	table->finished = FALSE;
	table->forks = new_forks(&table);
	if (!table->forks)
		return (FALSE);
	table->philos = new_philos(&table);
	if (!table->philos)
	{
		i = 0;
		while (i < (size_t)table->members)
		{
			pthread_mutex_destroy(&table->forks[i]);
			i++;
		}
		free(table->forks);
		table->forks = NULL;
		return (FALSE);
	}
	return (TRUE);
}

static void	set_input_at(char **in, t_table *table)
{
	table->members = ft_atol(in[1]);
	table->time_to_die = ft_atol(in[2]);
	table->time_to_eat = ft_atol(in[3]);
	table->time_to_sleep = ft_atol(in[4]);
	table->limit_meals = -1;
	if (in[5])
		table->limit_meals = ft_atol(in[5]);
}

static pthread_mutex_t	*new_forks(t_table *table)
{
	pthread_mutex_t	*forks;
	size_t			i;

	if (table->members <= 0)
		return (NULL);
	forks = malloc(table->members * sizeof(pthread_mutex_t));
	if (!forks)
		return (perr("It was not possible to allocate the forks\n"), NULL);
	i = 0;
	while (i < (size_t)table->members)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			perr("Initialization of mutual exclusion was not successful\n");
			while (i > 0)
			{
				i--;
				pthread_mutex_destroy(&forks[i]);
			}
			free(forks);
			return (NULL);
		}
		i++;
	}
	return (forks);
}

static t_philo	*new_philos(t_table *table)
{
	t_philo	*philos;
	size_t	i;

	if (table->members <= 0)
		return (NULL);
	philos = malloc(table->members * sizeof(t_philo));
	if (!philos)
		return (perr("It was not possible to allocate the philos\n"), NULL);
	i = 0;
	while (i < (size_t)table->members)
	{
		philos[i].id = i + 1;
		philos[i].last_meal = 0;
		philos[i].meals = 0;
		philos[i].left_fork = &table->forks[i];
		philos[i].right_fork = &table->forks[(i + 1) % table->members];
		philos[i].table = table;
		philos[i].satisfied = FALSE;
		if (!init_philo_mtx(philos, i))
			return (NULL);
		i++;
	}
	return (philos);
}

static t_philo	*init_philo_mtx(t_philo *philos, size_t idx)
{
	if (pthread_mutex_init(&philos[idx].meal, NULL) != 0)
	{
		perr("Initialization of mutual exclusion was not successful\n");
		while (idx > 0)
		{
			idx--;
			pthread_mutex_destroy(&philos[idx].meal);
		}
		free(philos);
		return (NULL);
	}
	return (philos);
}
