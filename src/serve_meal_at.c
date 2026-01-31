/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serve_meal_at.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:42:31 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/29 18:15:58 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	start_simulation(t_table *table);
static void	join_threads(t_table *table);

int	serve_meal_at(t_table *table)
{
	t_philo	**philos;
	int		sts;
	size_t	i;

	i = 0;
	tidy_up_utensils(table);
	start_simulation(table);
	join_threads(table);
	return (EXIT_SUCCESS);
}

static void	start_simulation(t_table *table)
{
	size_t	i;
	t_philo	**philos;
	int		sts;

	if (!table || (table && !table->philomenas))
		return ;
	i = 0;
	philos = table->philomenas;
	table->start_time = get_timestamp_ms();
	while (philos[i] && !table->is_finished)
	{
		sts = pthread_create(philos[i]->thread, NULL, philo_runtine, philos[i]);
		if (sts != 0)
		{
			cpinfo(ERROR, STDERR_FILENO, ERRMSG_THREAD);
			return (EXIT_FAILURE);
		}
		i++;
	}
	pthread_create(&table->monitor, NULL, monitor_runtine, table);
}

static void	join_threads(t_table *table)
{
	size_t	i;
	t_philo	**philos;

	if (!table)
		return ;
	i = 0;
	philos = table->philomenas;
	while (philos[i])
	{
		pthread_join(philos[i]->thread, NULL);
		i++;
	}
	pthread_join(table->monitor, NULL);
}
