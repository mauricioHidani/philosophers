/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serve_meal_at.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 21:51:54 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/04 00:07:43 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	init_sync_resources(t_table *table);
static void		set_finish(t_table *table);

void	serve_meal_at(t_table *table)
{
	size_t		i;
	t_philo		*phs;
	pthread_t	*monitor;

	i = 0;
	phs = table->philos;
	if (!init_sync_resource(table))
		return ;
	while (i < (size_t)table->members)
	{
		if (pthread_create(&phs[i].thread, NULL, philo_runtine, &phs[i]) != 0)
		{
			perr("");
			printf("%sThread of philo %d creation failed%s\n", RED, i + 1, RST);
			set_finish(table);
			break ;
		}
		i++;
	}
	monitor = table->thread;
	if (pthread_create(monitor, NULL, monitor_runtine, monitor) != 0)
	{
		perr("The thread of monitor creation failed\n");
		set_finish(table);
	}
}

static t_bool	init_sync_resources(t_table *table)
{
	table->start = get_timestamp();
	if (pthread_mutex_init(&table->print, NULL) != 0)
	{
		perr("Initialization of the print resource failed\n");
		return (FALSE);
	}
	if (phread_mutex_init(&table->state, NULL) != 0)
	{
		perr("Initialization of the state resource failed\n");
		pthread_mutex_destroy(&table->print);
		return (FALSE);
	}
	return (TRUE);
}

static void	set_finish(t_table *table)
{
	pthread_mutex_lock(&table->state);
	table->finished = TRUE;
	pthread_mutex_unlock(&table->state);
}
