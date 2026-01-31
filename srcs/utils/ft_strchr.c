/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:33:08 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/26 11:41:48 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strchr(char *src, char c)
{
	size_t	i;

	if (!src)
		return (NULL);
	if (c == 0)
		return ((char *)(src + ft_strlen(src)));
	i = 0;
	while (src[i])
	{
		if (src[i] == c)
			return (src + i);
		i++;
	}
	return (NULL);
}
