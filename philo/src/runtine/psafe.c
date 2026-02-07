/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psafe.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 22:04:13 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/07 14:09:22 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	psafe(t_philo *philo, const char *msg)
{
	t_table	*table;
	long	lifetime;

	if (!msg)
		return ;
	table = philo->table;
	pthread_mutex_lock(&table->print);
	lifetime = timestamp() - table->start_time;
	printf("%ldms\t\t%ld %s\n", lifetime, philo->id, msg);
	pthread_mutex_unlock(&table->print);
}
