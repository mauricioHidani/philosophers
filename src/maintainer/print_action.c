/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 09:58:52 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/29 14:38:34 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, char *action)
{
	char	*id;
	char	*time_elapsed;
	size_t	printed;

	pthread_mutex_lock(&philo->table->print_mtx);
	id = ft_itoa(philo->id);
	time_elapsed = ft_ltoa(get_timestamp_ms() - philo->table->start_time);
	printed = 0;
	printed += cfprint_reset(STDOUT_FILENO, BLUE_ITALIC, time_elapsed);
	printed += cfprint_reset(STDOUT_FILENO, BOLD, id);
	if (ft_strncmp(action, MSG_DIED, ft_strlen(MSG_DIED)) == 0)
		printed += cfprint_reset(STDOUT_FILENO, RED_ITALIC, action);
	else
		printed += cfprint_reset(STDOUT_FILENO, GREEN_ITALIC, action);
	printed += cprint(STDOUT_FILENO, "\n");
	if (printed == 0)
		cpinfo(ERROR, STDERR_FILENO, ERRMSG_PRINT);
	free(time_elapsed);
	free(id);
	pthread_mutex_unlock(&philo->table->print_mtx);
}
