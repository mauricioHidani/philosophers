/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cfprint_reset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:18:03 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/29 14:34:49 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	cfprint_reset(int fd, char *format, char *src)
{
	size_t	counter;

	if (fd < 0 | !src)
		return (0);
	if (!format)
		format = DEFAULT_COLOR;
	cprint(fd, format);
	counter = cprint(fd, src);
	cprint(fd, DEFAULT_COLOR);
	return (counter);
}
