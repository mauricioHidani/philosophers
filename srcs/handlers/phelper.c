/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phelper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:29:15 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/29 17:03:25 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	phelper(void)
{
	size_t	printed;
	int		fd;

	fd = STDERR_FILENO;
	printed = 0;
	printed += cpinfo(fd, WARNING, "The input is incorrect!");
	printed += cpinfo(fd, INFO, "./bin/philo <1> <2> <3> <4> [5]");
	cprint(fd, ITALIC);
	printed += cprint(fd, "\t1. Amount philosophers [mandatory]\n");
	printed += cprint(fd, "\t2. Time to die [mandatory]\n");
	printed += cprint(fd, "\t3. Time to eat [mandatory]\n");
	printed += cprint(fd, "\t4. Time to sleep [mandatory]\n");
	printed += cprint(
		fd, "\t5. Number of times each philosopher must eat [optional]\n");
	cprint(fd, DEFAULT_COLOR);
	if (printed == 0)
	{
		cpinfo(ERROR, STDERR_FILENO, ERRMSG_PRINT);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
