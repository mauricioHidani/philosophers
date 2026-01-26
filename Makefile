# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/25 23:14:40 by mhidani           #+#    #+#              #
#    Updated: 2026/01/25 23:20:31 by mhidani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# INFO
NAME		= philo
LOCAL		= 42sp
VERSION		= 1.0.0v
AUTHORS		= mhidani (Mauricio Mityo Hidani)
SINCE		= 17 November 2025

# BASIC CONTROLLERS
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
ARCHIVER	= ar
ARFLAGS		= -rcs
VALGRIND	= valgrind
VFLAGS		= --leak-check=full --show-leak-kinds=all
MKDIR		= mkdir
MKDFLAGS	= --parents
REMOVE		= rm
RMFLAGS		= --recursive --force

# BASE DIRECTORIES
SRCS_DIR	= srcs
LIBS_DIR	= libs
OBJS_DIR	= objs

## SUB DIRECTORIES
UTILS_DIR	= utils

# EXECUTABLE PROJECT
EXECUTABLE	= $(BIN_DIR)/$(NAME)

# C FILES
EXEC_FILE	= main.c
SRCS_FILES	= 
UTILS_FILES	= 

SRCS		= $(addprefix $(SRCS_DIR)/, $(EXEC_FILE))
LIBS		= $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

# COLORS
GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

all: $(EXECUTABLE)

$(EXECUTABLE): $(LIB) $(SRCS)
	@$(CC) $(CLFAGS) $^ -o $@
	@echo "🛸The Philosophers project is done!"

$(LIB): $(OBJS) | $(LIB_DIR)
	@$(AR) $(ARFLAGS) $@ $^
	@echo "📦The Static Library is ready!"

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "[$(GREEN)COMPILED$(RESET)] $<"

$(LIB_DIR):
	@$(MKDIR) $(MKFLAGS) $@
	@echo "📁Create Directory $@"

$(LIB_DIR):
	@$(MKDIR) $(MKFLAGS) $@
	@echo "📁Create Directory $@"

$(OBJS_DIR):
	@$(MKDIR) $(MKFLAGS) $@
	@echo "📁Create Directory $@"

clean:
	@$(REMOVE) $(RMFLAGS) $(OBJS_DIR)
	@echo "[$(RED)REMOVED$(RESET)] Cleaned object files."

fclean: clean
	@$(REMOVE) $(RMFLAGS) $(LIBS_DIR)
	@echo "[$(RED)CLEAN$(RESET)] Library."
	@$(REMOVE) $(RMFLAGS) $(NAME)
	@echo "[$(RED)CLEAN$(RESET)] Executable Philosophers project."

re: fclean re

.PHONY: all clean fclean re valgrind
