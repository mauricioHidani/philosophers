/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:12:56 by mhidani           #+#    #+#             */
/*   Updated: 2025/11/06 16:29:39 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define SUCCESS 0x00
# define FAILURE 0x01

# define TRUE 0x01
# define FALSE 0x00

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>

typedef char	t_bool;

typedef struct s_manager
{
	int 	number_of_philosophers;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	times_you_should_eat;
}	t_manager;

// Auxiliar
t_bool		ft_isspace(char c);
long		ft_atol(char *str);
t_bool		ft_isdigit(char c);
size_t		ft_putstr_fd(char *str, int fd);

// Manager Utils
void		ft_manager_assign(int argc, char **argv, t_manager *manager);
t_manager	*ft_new_manager(void);
void		ft_clean_manager(void *ptr);

// Table for the pasta dinner
void		set_table_pasta_dinner(t_manager *manager);

#endif
