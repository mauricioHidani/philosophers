/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:45:44 by mhidani           #+#    #+#             */
/*   Updated: 2025/11/27 11:47:46 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clist.h"

void	ft_clean_node(t_node *node, void (*clean)(void *))
{
	if (!node)
		return ;
	clean(node->data);
	free(node);
}
