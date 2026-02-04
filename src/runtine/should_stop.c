/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   should_stop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:09:32 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/03 15:09:36 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	should_stop(t_table *table)
{
	t_bool	finished;

	pthread_mutex_lock(&table->state);
	finished = table->finished;
	pthread_mutex_unlock(&table->state);
	return (finished);
}
