# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/25 23:14:40 by mhidani           #+#    #+#              #
#    Updated: 2026/01/31 15:19:11 by mhidani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# INFO
NAME			= philo
LOCAL			= 42sp
VERSION			= 1.0.0v
AUTHORS			= mhidani (Mauricio Mityo Hidani)
SINCE			= 17 November 2025

# BASE DIRECTORIES
INCS_DIR		= includes
SRCS_DIR		= srcs
OBJS_DIR		= objs
BIN_DIR			= bin

## SUB DIRECTORIES
START_DIR		= starter
HADLS_DIR		= handlers
MANTS_DIR		= maintainers
STRCS_DIR		= structures
UTILS_DIR		= utils

## SUB SOURCES DIRECTORIES
SRCS_START_DIR	= $(SRCS_DIR)/$(START_DIR)
SRCS_HADLS_DIR	= $(SRCS_DIR)/$(HADLS_DIR)
SRCS_MANTS_DIR	= $(SRCS_DIR)/$(MANTS_DIR)
SRCS_STRCS_DIR	= $(SRCS_DIR)/$(STRCS_DIR)
SRCS_UTILS_DIR	= $(SRCS_DIR)/$(UTILS_DIR)

## SUB OBJECTS DIRECTORIES
OBJS_START_DIR	= $(OBJS_DIR)/$(START_DIR)
OBJS_HADLS_DIR	= $(OBJS_DIR)/$(HADLS_DIR)
OBJS_MANTS_DIR	= $(OBJS_DIR)/$(MANTS_DIR)
OBJS_STRCS_DIR	= $(OBJS_DIR)/$(STRCS_DIR)
OBJS_UTILS_DIR	= $(OBJS_DIR)/$(UTILS_DIR)

TGT_OBJS_DIR	= $(BIN_DIR) $(OBJS_START_DIR) $(OBJS_HADLS_DIR) \
				  $(OBJS_MANTS_DIR) $(OBJS_STRCS_DIR) $(OBJS_UTILS_DIR)

# HEADER
HEADERS			= $(INCS_DIR)/philo.h $(INCS_DIR)/utils.h $(INCS_DIR)/type.h

# C FILES
EXEC_FILE		= main.c
START_FILES		= serve_meal_at.c
HADLS_FILES		= phelper.c
MANTS_FILES		= monitor_runtine.c philo_eat.c philo_runtine.c philo_sleep.c \
				  philo_think.c print_action.c
STRCS_FILES		= cleanup.c destroy_forks.c destroy_philos.c new_philo.c \
				  new_philos.c new_table.c parse_input.c tidy_up_utensils.c
UTILS_FILES		= cfprint.c cfprint_reset.c cpinfo.c cprint.c ft_atoi.c \
				  ft_atol.c ft_bzero.c ft_calloc.c ft_isspace.c \
				  ft_itoa.c ft_ltoa.c ft_strchr.c ft_strdup.c ft_strlen.c \
				  ft_strncmp.c get_timestamp_ms.c sleep_for.c

# FINAL SOURCE FILES
MAIN			= $(SRCS_DIR)/$(EXEC_FILE)
SRCS			= $(MAIN) \
				  $(addprefix $(SRCS_START_DIR)/, $(START_FILES)) \
				  $(addprefix $(SRCS_HADLS_DIR)/, $(HADLS_FILES)) \
				  $(addprefix $(SRCS_MANTS_DIR)/, $(MANTS_FILES)) \
				  $(addprefix $(SRCS_STRCS_DIR)/, $(STRCS_FILES)) \
				  $(addprefix $(SRCS_UTILS_DIR)/, $(UTILS_FILES)) \

# FINAL OBJECT FILES
OBJS			= $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

# EXECUTABLE FILE
EXECUTABLE		= $(BIN_DIR)/$(NAME)

# BASIC CONTROLLERS
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
IFLAGS			= -I $(INCS_DIR)/
BFLAGS			= -lpthread
ARCHIVER		= ar
ARFLAGS			= -rcs
VALGRIND		= valgrind
VFLAGS			= --leak-check=full --show-leak-kinds=all
MKDIR			= mkdir
MKDFLAGS		= --parents
REMOVE			= rm
RMFLAGS			= --recursive --force

# COLORS
GREEN			= "\033[0;32m"
RED				= "\033[0;31m"
ORANGE			= "\033[0;38;2;255;163;72;49m"
RESET			= "\033[0m"
OK				= "[$(GREEN)OK$(RESET)]"
KO				= "[$(RED)KO$(RESET)]"
CLEAN			= "[$(ORANGE)CLEANED$(RESET)]"

all: $(EXECUTABLE)

$(EXECUTABLE): $(MAIN) $(OBJS) | $(BIN_DIR)
	@$(CC) $(CLFAGS) $(IFLAGS) $^ $(BFLAGS) -o $@
	@echo "$(OK) 📁 Directory created for the binary"
	@echo "$(OK) 🛸 The Philosophers project is done!"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS) | $(TGT_OBJS_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@echo "$(OK) 📁 Create Directory $(BIN_DIR)"
	@echo "$(OK) 📁 Create Directory $(OBJS_START_DIR)"
	@echo "$(OK) 📁 Create Directory $(OBJS_HADLS_DIR)"
	@echo "$(OK) 📁 Create Directory $(OBJS_MANTS_DIR)"
	@echo "$(OK) 📁 Create Directory $(OBJS_STRCS_DIR)"
	@echo "$(OK) 📁 Create Directory $(OBJS_UTILS_DIR)"
	@echo "$(OK) 📄 Compiled $<"

$(BIN_DIR):
	@$(MKDIR) $(MKFLAGS) $@
	@echo "$(OK) 📁 Create Directory $@"

$(TGT_OBJS_DIR):
	@$(MKDIR) $(MKDFLAGS) $<
	@echo "$(OK) 📁 Create Directory $@"

clean:
	@$(REMOVE) $(RMFLAGS) $(OBJS_DIR)
	@echo "$(CLEAN) 📤 Cleaned object files."

fclean: clean
	@$(REMOVE) $(RMFLAGS) $(BIN_DIR)
	@echo "$(CLEAN) 📤 Executable Philosophers project."

re: fclean all

.PHONY: all clean fclean re valgrind
