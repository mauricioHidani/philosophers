# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/31 20:02:33 by mhidani           #+#    #+#              #
#    Updated: 2026/02/03 07:23:07 by mhidani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
VERSION		= 1.0.0v
AUTHOR		= mhidani
LOCAL		= "42 São Paulo"
SINCE		= "17 November 2025"

SRC_DIR		= src
OBJ_DIR		= obj
INCLUDE_DIR	= include
BIN_DIR		= bin

UTIL_DIR	= util
CTOR_DIR	= ctor
STRT_DIR	= starter
RUNT_DIR	= runtine

MAIN_FILE	= main.c
UTIL_FILES	= ft_strlen.c ft_strncmp.c ft_isspace.c ft_atoi.c ft_atol.c \
			  ft_bzero.c ft_calloc.c get_timestamp_ms.c wait_for_ms.c
CTOR_FILES	= new_table.c destroy_table.c new_philos.c destroy_philos.c \
			  new_forks.c destroy_forks.c
STRT_FILES	= serve_meal_at.c
RUNT_FILES	= monitor_runtine.c philo_runtine.c philo_eat.c philo_think.c \
			  philo_sleep.c should_stop.c print.c

FILES		= $(wildcard $(SRC_DIR)/*.c)
SRC			= $(addprefix $(SRC_DIR)/, $(FILES))
OBJ			= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

EXC			= $(BIN_DIR)/$(NAME)

CC			= cc
CFLAGS		= -g -O0 -pthread -Wall -Wextra -Werror
IFLAGS		= -I $(INCLUDE_DIR)/
BFLAGS		= -lpthread

VALGRIND	= valgrind
VFLAGS		= --leak-check=full --track-origins=yes --show-leak-kinds=all
VARGS		?= "2 200 100 100 7"

MKDIR		= mkdir
MKDFLAGS	= --parents

all: $(EXC)

$(EXC): $(BIN_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) $(FILES) $(BFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(MKDIR) $(MKDFLAGS) $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(BIN_DIR):
	$(MKDIR) $(MKDFLAGS) $@

$(VALGRIND): re
	$(VALGRIND) $(VFLAGS) $(EXC) $(VARGS)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(BIN_DIR)

re: fclean all

.PHONY: clean fclean all re
