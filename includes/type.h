/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 09:42:25 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/28 16:58:20 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# define TRUE 0x01
# define FALSE 0x00

# define RED "\033[0;38;2;237;51;59;49m"
# define RED_BOLD "\033[1;38;2;237;51;59;49m"
# define RED_ITALIC "\033[3;38;2;237;51;59;49m"
# define RED_BOLD_ITALIC "\033[1;3;38;2;237;51;59;49m"
# define GREEN "\033[0;38;2;87;227;137;49m"
# define GREEN_BOLD "\033[1;38;2;87;227;137;49m"
# define GREEN_ITALIC "\033[3;38;2;87;227;137;49m"
# define GREEN_BOLD_ITALIC "\033[1;3;38;2;87;227;137;49m"
# define BLUE "\033[0;38;2;98;160;234;49m"
# define BLUE_BOLD "\033[1;38;2;98;160;234;49m"
# define BLUE_ITALIC "\033[3;38;2;98;160;234;49m"
# define BLUE_BOLD_ITALIC "\033[1;3;38;2;98;160;234;49m"
# define ORANGE "\033[0;38;2;255;163;72;49m"
# define ORANGE_ITALIC "\033[3;38;2;255;163;72;49m"
# define ORANGE_BOLD "\033[1;38;2;255;163;72;49m"
# define ORANGE_BOLD_ITALIC "\033[1;3;38;2;255;163;72;49m"
# define BOLD "\033[1m"
# define ITALIC "\033[3m"
# define BOLD_ITALIC "\033[1;3m"
# define DEFAULT_COLOR "\033[0m"

# define ERRMSG_ALLOC "It was not possible to allocate memory of this type"
# define ERRMSG_DESTROY "There was no correct destruction for the type"

typedef char			t_bool;

#endif
