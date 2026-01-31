/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:44:24 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/29 17:51:37 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup(t_table *table)
{
	if (!table)
		return ;
	destroy_forks(table->forks);
	destroy_philos(table->philomenas);
	pthread_mutex_destroy(&table->print_mtx);
	pthread_mutex_destroy(&table->death_mtx);
	free(table);
}
