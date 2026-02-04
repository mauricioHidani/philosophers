/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:47:41 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/03 23:46:04 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	print(int fd, const char *src);

void	perr(const char *src)
{
	int		fd;
	size_t	printed;

	if (!src)
		return ;
	printed = 0;
	fd = STDERR_FILENO;
	print(fd, RED);
	printed += print(fd, "[error] ");
	printed += print(fd, src);
	print(fd, RST);
	if (printed == 0)
		write(STDERR_FILENO, "error when print\n", 17);
}

void	pinfo(const char *src)
{
	int		fd;
	size_t	printed;

	if (!src)
		return ;
	printed = 0;
	fd = STDOUT_FILENO;
	print(fd, BLUE);
	printed += print(fd, "[info] ");
	printed += print(fd, src);
	print(fd, RST);
	if (printed == 0)
		write(STDERR_FILENO, "error when print\n", 17);
}

void	pwarning(const char *src)
{
	int		fd;
	size_t	printed;

	if (!src)
		return ;
	printed = 0;
	fd = STDOUT_FILENO;
	print(fd, ORANGE);
	printed += print(fd, "[warning] ");
	printed += print(fd, src);
	print(fd, RST);
	if (printed == 0)
		write(STDERR_FILENO, "error when print\n", 17);
}

void	psafe(t_philo *philo, const char *src)
{
	t_table	*table;
	long	lifetime;
	char	*format;

	table = philo->table;
	pthread_mutex_lock(&table->state);
	if (table->finished && ft_strncmp(src, DIED, ft_strlen(DIED)) != 0)
	{
		pthread_mutex_unlock(&table->state);
		return ;
	}
	pthread_mutex_unlock(&table->state);
	lifetime = get_timestamp() - table->start;
	format = ITALIC;
	if (ft_strncmp(src, DIED, ft_strlen(DIED)) == 0)
		format = RED_ITALIC;
	pthread_mutex_lock(&table->print);
	printf("%s%ld%s", ORANGE, lifetime, RST);
	printf("\t%s%d%s", BLUE, philo->id, RST);
	printf("\t%s%s%s", format, src, RST);
	printf("\n");
	pthread_mutex_unlock(&table->print);
}

static size_t	print(int fd, const char *src)
{
	size_t	i;

	if (!src || fd < 0)
		return (0);
	i = 0;
	while (src[i])
		i += write(fd, &src[i], 1);
	return (i);
}
