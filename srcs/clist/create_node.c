/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:40:50 by mhidani           #+#    #+#             */
/*   Updated: 2025/11/27 11:42:06 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clist.h"

t_node	*ft_create_node(void *data)
{
	t_node	*node;

	if (!data)
		return (NULL);
	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
