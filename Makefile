# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/31 20:02:33 by mhidani           #+#    #+#              #
#    Updated: 2026/02/04 09:20:05 by mhidani          ###   ########.fr        #
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
RUNT_DIR	= runtine

SB_UTIL_DIR	= $(SRC_DIR)/$(UTIL_DIR)
SB_CTOR_DIR	= $(SRC_DIR)/$(CTOR_DIR)
SB_RUNT_DIR	= $(SRC_DIR)/$(RUNT_DIR)

MAIN_FILE	= main.c
UTIL_FILES	= ft_atol.c ft_strlen.c ft_strncmp.c phelper.c print.c time.c
CTOR_FILES	= check_input.c cleanup.c init_table.c serve_meal_at.c \
			  wait_for_end.c
RUNT_FILES	= monitor_runtine.c philo_eat.c philo_runtine.c philo_sleep.c \
			  philo_think.c should_stop.c

SRC			= $(addprefix $(SRC_DIR)/, $(MAIN_FILE)) \
			  $(addprefix $(SB_UTIL_DIR)/, $(UTIL_FILES)) \
			  $(addprefix $(SB_CTOR_DIR)/, $(CTOR_FILES)) \
			  $(addprefix $(SB_RUNT_DIR)/, $(RUNT_FILES))

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
RM			= rm
RMFLAGS		= --recursive --force

all: $(EXC)

$(EXC): $(OBJ) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) $^ $(BFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(MKDIR) $(MKDFLAGS) $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(BIN_DIR):
	$(MKDIR) $(MKDFLAGS) $@

$(VALGRIND): re
	$(VALGRIND) $(VFLAGS) $(EXC) $(VARGS)

clean:
	$(RM) $(RMFLAGS) $(OBJ_DIR)

fclean: clean
	$(RM) $(RMFLAGS) $(BIN_DIR)

re: fclean all

.PHONY: clean fclean all re
