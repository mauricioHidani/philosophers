/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_runtine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:58:58 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/29 18:21:03 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_runtine(void *ptr)
{
	t_table	*table;
	t_philo	*philo;

	if (!ptr)
		return ;
	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		usleep(200);
	table = philo->table;
	while (!table->is_finished)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		if (table->limit_meals != -1 && philo->meals >= table->limit_meals)
			break ;
	}
	return (NULL);
}
