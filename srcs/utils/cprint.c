/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cprint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 23:32:30 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/31 15:02:21 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	cprint(int fd, char *src)
{
	size_t	i;

	if (!src || fd < 0)
		return (0);
	i = 0;
	while (src[i])
		i += write(fd, &src[i], 1);
	return (i);
}
