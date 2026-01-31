/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpinfo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:12:13 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/29 14:35:33 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	cpinfo(t_info_type type, int fd, char *src)
{
	size_t	counter;

	if (!src || fd < 0)
		return (0);
	if (type == INFO)
		counter = cfprint(fd, BLUE, "[info] ");
	else if (type == WARNING)
		counter = cfprint(fd, ORANGE, "[warning] ");
	else if (type == ERROR)
		counter = cfprint(fd, RED, "[error] ");
	else
		counter = cfprint(fd, DEFAULT_COLOR, "[default] ");
	counter += cprint(fd, src);
	counter += cprint(fd, "\n");
	cprint(fd, DEFAULT_COLOR);
	return (counter);
}
