/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 09:29:50 by mhidani           #+#    #+#             */
/*   Updated: 2025/11/28 09:31:51 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_putstr_fd(char *str, int fd)
{
	size_t	i;

	if (!str || fd < 0)
		return (0);
	i = 0;
	while (str[i])
		i += write(fd, str[i], 1);
	return (i);
}
