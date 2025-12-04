/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:50:46 by mhidani           #+#    #+#             */
/*   Updated: 2025/12/04 01:16:28 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_wait_for_time(long ms)
{
	long	start;
	long	current;

	start = ft_get_time();
	while (TRUE)
	{
		current = ft_get_time();
		if (current - start >= ms)
			break ;
		if (ms - (current - start) > 1)
			usleep(500);
		else
			usleep(100);
	}
}
