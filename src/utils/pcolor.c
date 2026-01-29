/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pcolor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:16:19 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/28 15:57:22 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	pcolor(int fd, char *color, char *src)
{
	size_t	i;
	size_t	printed;

	if (!color || fd < 0)
		return ;
	cprint(fd, color);
	printed = cprint(fd, src);
	return (printed);
}
