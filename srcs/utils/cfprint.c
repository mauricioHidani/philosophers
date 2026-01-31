/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cfprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:16:19 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/31 15:17:19 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	cfprint(int fd, char *format, char *src)
{
	size_t	counter;

	if (!format || fd < 0)
		return (0);
	cprint(fd, format);
	counter = cprint(fd, src);
	return (counter);
}
