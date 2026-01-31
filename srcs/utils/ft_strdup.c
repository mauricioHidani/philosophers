/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:56:33 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/28 11:58:14 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strdup(char *src)
{
	size_t	i;
	size_t	size;
	char	*new;

	if (!src)
		return (NULL);
	size = ft_strlen(src);
	new = ft_calloc(size + 1, sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	return (new);
}
