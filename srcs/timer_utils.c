/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:21:14 by mhidani           #+#    #+#             */
/*   Updated: 2025/11/28 11:26:07 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_timer	ft_create_timer(long end_offset)
{
	t_timer	timer;

	gettimeofday(&timer.start, NULL);
	timer.current = timer.start;
	timer.end.tv_usec = timer.start.tv_usec + end_offset * 1000;
	return (timer);
}

t_bool	ft_its_not_over(t_timer timer)
{
	return (timer.current.tv_usec < timer.end.tv_usec);
}
