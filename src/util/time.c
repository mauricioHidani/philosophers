/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 08:41:26 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/03 15:11:46 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_timestamp(void)
{
	struct timeval	tv;
	long			ms;

	if (gettimeofday(&tv, NULL) != 0)
		return (-1);
	ms = tv.tv_sec * 1e3 + tv.tv_usec / 1e3;
	return (ms);
}

void	wait_ms(t_table *table, long ms)
{
	long	end;

	end = get_timestamp() + ms;
	while (get_timestamp() < end)
	{
		if (should_stop(table))
			break ;
		usleep(200);
	}
}
