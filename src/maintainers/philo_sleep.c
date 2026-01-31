/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:00:51 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/29 15:49:24 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	print_action(philo, MSG_SLEEPING);
	sleep_for(table->time_to_sleep, table->is_finished);
}
