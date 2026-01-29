/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phelper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:29:15 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/28 21:19:14 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	phelper(void)
{
	size_t	printed;
	int		fd;

	fd = STDERR_FILENO;
	printed = 0;
	printed += pinfo(fd, WARNING, "The input is incorrect!");
	printed += pinfo(fd, INFO, "./bin/philo <1> <2> <3> <4> [5]");
	cprint(fd, ITALIC);
	printed += cprint(fd, "\t1. Amount philosophers [mandatory]\n");
	printed += cprint(fd, "\t2. Time to die [mandatory]\n");
	printed += cprint(fd, "\t3. Time to eat [mandatory]\n");
	printed += cprint(fd, "\t4. Time to sleep [mandatory]\n");
	printed += cprint(
		fd, "\t5. Number of times each philosopher must eat [optional]\n");
	cprint(fd, DEFAULT_COLOR);
	return (cprint);
}
