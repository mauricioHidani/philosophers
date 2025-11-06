/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:21:58 by mhidani           #+#    #+#             */
/*   Updated: 2025/11/06 15:24:21 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	ft_putstr_fd(char *str, int fd)
{
	size_t	i;

	if (!str || fd < 0)
		return (0);
	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
	return (i);
}
