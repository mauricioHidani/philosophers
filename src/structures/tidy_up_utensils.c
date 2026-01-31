/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tidy_up_utensils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:43:30 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/29 17:57:54 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	tidy_up_utensils(t_table *table)
{
	size_t	i;

	if (!table)
		return ;
	i = 0;
	while (table->forks[i])
	{
		pthread_mutex_init(table->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&table->print_mtx, NULL);
	pthread_mutex_init(&table->death_mtx, NULL);
}
