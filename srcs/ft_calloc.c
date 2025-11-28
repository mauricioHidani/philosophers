/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:24:51 by mhidani           #+#    #+#             */
/*   Updated: 2025/11/28 13:36:27 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*res;
	unsigned char	*mod;
	size_t			i;

	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (size != 0 && nmemb > (size_t)-1 / size)
		return (NULL);
	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	mod = (unsigned char *)res;
	i = 0;
	while (i < (nmemb * size))
	{
		mod[i] = 0;
		i++;
	}
	return (res);
}
