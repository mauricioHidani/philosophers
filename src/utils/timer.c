/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 23:48:06 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/26 00:01:15 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_timestamp_ms(void)
{
	struct timeval	tvalue;
	long			timestamp;

	gettimeofday(&tvalue, NULL);
	timestamp = tvalue.tv_sec * 1000 + tvalue.tv_usec / 1000;
	return (timestamp);
}

void	sleep_for(long duration)
{
	long	start;
	long	current;

	start = get_timestamp_ms();
	current = get_timestamp_ms() - start;
	while (current <= duration)
	{
		current = get_timestamp_ms() - start;
		usleep(250);
	}
}
