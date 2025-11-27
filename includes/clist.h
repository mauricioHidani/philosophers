/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:36:23 by mhidani           #+#    #+#             */
/*   Updated: 2025/11/27 13:01:53 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIST_H
# define CLIST_H

# include <stdlib.h>

typedef struct s_node
{
	unsigned long	id;
	void			*data;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_clist
{
	t_node			*top;
	t_node			*bottom;
	unsigned long	size;
}	t_clist;

t_clist	*ft_create_clist(void *data, void (*clean)(void *));
t_node	*ft_create_node(void *data);
t_clist	*ft_add_node_clist(t_clist *list, void *data);
void	ft_clean_node(t_node *node, void (*clean)(void *));
void	ft_clean_clist(t_clist *list, void (*clean_data)(void *));

#endif
