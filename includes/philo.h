/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:33:06 by mhidani           #+#    #+#             */
/*   Updated: 2025/12/02 17:18:20 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>

# define TRUE 0x01
# define FALSE 0x00

typedef char	t_bool;

// Utilities -------------------------------------------------------------------
void	ft_print_help(void);
void	*ft_calloc(size_t nmemb, size_t size);
t_bool	ft_isspace(char c);
t_bool	ft_isdigit(char c);
long	ft_atol(char *src);
