/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 09:33:55 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/30 18:46:58 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include "type.h"

# define BINARY_BASE "01"
# define OCTAL_BASE "01234567"
# define DECIMAL_BASE "0123456789"
# define HEXDECIMAL_BASE "0123456789ABCDEF"
# define SHEXDECIMAL_BASE "0123456789abcdef"

typedef enum e_info_type
{
	INFO,
	WARNING,
	ERROR,
}	t_info_type;

// Check and Manipulate --------------------------------------------------------

t_bool	ft_isspace(char c);

// -------------------------------------------------------- Check and Manipulate

// Write -----------------------------------------------------------------------

size_t	cprint(int fd, char *src);
size_t	cfprint(int fd, char *format, char *src);
size_t	cfprint_reset(int fd, char *format, char *src);
size_t	cpinfo(t_info_type type, int fd, char *src);

// ----------------------------------------------------------------------- Write

// String Manipulate -----------------------------------------------------------

size_t	ft_strlen(char *src);
char	*ft_strchr(char *src, char c);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strdup(char *src);

// ----------------------------------------------------------- String Manipulate

// Manipulete Memory -----------------------------------------------------------

void	ft_bzero(void *mem, size_t size);
void	*ft_calloc(size_t nmemb, size_t size);

// ----------------------------------------------------------- Manipulete Memory

// Number ----------------------------------------------------------------------

int		ft_atoi(char *nbr);
long	ft_atol(char *nbr);
char	*ft_itoa(int nbr);
char	*ft_ltoa(long nbr);

// ---------------------------------------------------------------------- Number

// Time ------------------------------------------------------------------------

long	get_timestamp_ms(void);
void	sleep_for(long duration, t_bool no_action);

// ------------------------------------------------------------------------ Time

#endif