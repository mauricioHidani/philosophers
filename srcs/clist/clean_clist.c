/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_clist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:44:28 by mhidani           #+#    #+#             */
/*   Updated: 2025/11/27 12:55:39 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clist.h"

void	ft_clean_clist(t_clist *list, void (*clean_data)(void *))
{
	t_node	*pivot;
	t_node	*aux;

	if (!list)
		return ;
	pivot = list->top;
	while (pivot)
	{
		clean_data(pivot->data);
		aux = pivot;
		pivot = pivot->next;
		pivot->prev = NULL;
		free(aux);
	}
	free(list);
}
