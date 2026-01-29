/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:07:07 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/26 11:09:23 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_bzero(void *mem, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	if (!mem || size == 0)
		return ;
	i = 0;
	ptr = (unsigned char *)mem;
	while (i < size)
	{
		ptr[i] = 0;
		i++;
	}
}
