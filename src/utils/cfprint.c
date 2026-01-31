/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cfprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:16:19 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/29 14:35:36 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	cfprint(int fd, char *format, char *src)
{
	size_t	i;
	size_t	counter;

	if (!format || fd < 0)
		return ;
	cprint(fd, format);
	counter = cprint(fd, src);
	return (counter);
}
