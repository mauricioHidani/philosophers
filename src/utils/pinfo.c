/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pinfo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:12:13 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/28 15:54:28 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	pinfo(t_info_type type, int fd, char *src)
{
	size_t	printed;

	if (!src || fd < 0)
		return (0);
	if (type == INFO)
		printed = pcolor(fd, BLUE, "[info] ");
	else if (type == WARNING)
		printed = pcolor(fd, ORANGE, "[warning] ");
	else if (type == ERROR)
		printed = pcolor(fd, RED, "[error] ");
	else
		printed = pcolor(fd, DEFAULT_COLOR, "[default] ");
	printed += cprint(fd, src);
	printed += cprint(fd, "\n");
	cprint(fd, DEFAULT_COLOR);
	return (printed);
}
