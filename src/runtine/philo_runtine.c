/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_runtine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:46:19 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/03 15:11:16 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_runtine(void *arg)
{
	t_philo	*philo;
	t_table	*table;

	if (!arg)
		return (NULL);
	philo = (t_philo *)arg;
	table = philo->table;
	if (philo->id % 2 == 0)
		usleep(1e3);
	pthread_mutex_lock(&philo->meal);
	philo->last_meal = get_timestamp();
	pthread_mutex_unlock(&philo->meal);
	while (!should_stop(table) || !philo->satisfied)
	{
		if (!philo_eat(philo))
			break ;
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}
