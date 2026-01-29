/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serve_meal_at.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:42:31 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/28 21:25:07 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	serve_meal_at(t_table *table)
{
	t_philo	**philos;

	philos = accommodate_philos_at(table);
	table->start_time = get_timestamp_ms();
	while (table->is_finished != FALSE)
	{
		// TODO: inicializar o processo dos filosofos
	}
	remove_philos(philos);
}
