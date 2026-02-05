/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:51:11 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/04 21:34:05 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	timestamp(void)
{
	struct timeval	tval;
	long			time;

	if (gettimeofday(&tval, NULL) != 0)
		return (-1);
	time = tval.tv_sec * 1e3 + tval.tv_usec / 1e3;
	return (time);
}

void	wait_time(t_table *table, long time)
{
	long	end;

	end = timestamp() + time;
	while (timestamp() < end)
	{
		if (should_stop(table))
			break ;
		usleep(200);
	}
}
