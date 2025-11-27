/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_clist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:56:21 by mhidani           #+#    #+#             */
/*   Updated: 2025/11/27 15:39:41 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clist.h"

t_clist	*ft_add_node_clist(t_clist *list, void *data)
{
	t_node	*node;

	if (!list || !data)
		return (NULL);
	node = ft_create_node(data);
	if (!node)
		return (NULL);
	list->bottom->next = node;
	node->prev = list->bottom;
	node->next = list->top;
	list->bottom = node;
	list->size += 1;
}
