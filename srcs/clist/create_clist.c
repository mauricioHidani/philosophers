/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cdlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:35:19 by mhidani           #+#    #+#             */
/*   Updated: 2025/11/27 11:53:22 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clist.h"

t_clist	*ft_create_clist(void *data, void (*clean)(void *))
{
	t_clist	*circular_list;
	t_node	*node;

	node = NULL;
	if (data)
	{
		node = ft_create_node(data);
		if (!node)
			return (NULL);
	}
	circular_list = malloc(sizeof(t_clist));
	if (!circular_list)
	{
		ft_clean_node(node, clean);
		return (NULL);
	}
	circular_list->top = node;
	circular_list->bottom = node;
	if (node)
		circular_list->size = 1;
	return (circular_list);
}
