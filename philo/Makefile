# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/04 22:28:11 by mhidani           #+#    #+#              #
#    Updated: 2026/02/05 11:02:07 by mhidani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# INFO -------------------------------------------------------------------------
NAME			= philo
AUTHOR			= mhidani
MAIL			= mhidani@student.42sp.org.br
LOCAL			= 42sp
VERSION			= 1.2.3v
# ------------------------------------------------------------------------- INFO

# DIRECTORIES ------------------------------------------------------------------
SRC_DIR			= src
INC_DIR			= include
OBJ_DIR			= obj
BIN_DIR			= bin
RUNT_DIR		= runtine
CORE_DIR		= core
INPUT_DIR		= input
UTIL_DIR		= util

SUB_RUNT_DIR	= $(SRC_DIR)/$(RUNT_DIR)
SUB_CORE_DIR	= $(SRC_DIR)/$(CORE_DIR)
SUB_INPUT_DIR	= $(SRC_DIR)/$(INPUT_DIR)
SUB_UTIL_DIR	= $(SRC_DIR)/$(UTIL_DIR)
# ------------------------------------------------------------------ DIRECTORIES

# FILES ------------------------------------------------------------------------
MAIN_FILE		= main.c
RUNT_FILES		= checkers.c monitor_runtine.c philo_runtine.c psafe.c forks.c
CORE_FILES		= cleanup.c init_table.c serve.c
INPUT_FILES		= checkin.c phelper.c
UTIL_FILES		= ft_atol.c ft_isdigit.c ft_isspace.c time.c
# ------------------------------------------------------------------------ FILES

# LIST OF COMPOSITE FILES ------------------------------------------------------
SRCS			= $(addprefix $(SRC_DIR)/, $(MAIN_FILE)) \
				  $(addprefix $(SUB_RUNT_DIR)/, $(RUNT_FILES)) \
				  $(addprefix $(SUB_CORE_DIR)/, $(CORE_FILES)) \
				  $(addprefix $(SUB_INPUT_DIR)/, $(INPUT_FILES)) \
				  $(addprefix $(SUB_UTIL_DIR)/, $(UTIL_FILES))

OBJS			= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

EXEC			= $(BIN_DIR)/$(NAME)
DEXC			= $(BIN_DIR)/debug
# ------------------------------------------------------ LIST OF COMPOSITE FILES

# PREPARATIONS -----------------------------------------------------------------
CC				= cc
BFLAGS			= -lpthread
CFLAGS			= -Wall -Wextra -Werror
DFLAGS			= -g -O0 -pthread -Wall -Wextra -Werror
IFLAGS			= -I $(INC_DIR)/

MKDIR			= mkdir
MKDFLAGS		= --parents
REMOVE			= rm
RMFLAGS			= --recursive --force
# ----------------------------------------------------------------- PREPARATIONS

# COLORS AND FORMAT ------------------------------------------------------------
GREEN			:= "\033[0;38;2;51;209;122;49m"
RED				:= "\033[0;38;2;224;27;36;49m"
BLUE			:= "\033[0;38;2;53;132;228;49m"
ORANGE			:= "\033[0;38;2;255;120;0;49m"
RST				:= "\033[0m"

OK				:= "[$(GREEN)OK$(RST)]"
KO				:= "[$(RED)KO$(RST)]"
CLEAN			:= "[$(ORANGE)CLEAN$(RST)]"

BANNER			:= banner
# ------------------------------------------------------------ COLORS AND FORMAT

all: $(BANNER) $(EXEC)

$(EXEC): $(OBJS)
	@$(MKDIR) $(MKDFLAGS) $(BIN_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) $^ $(BFLAGS) -o $@
	@echo "📁 Executable stored in $@"
	@echo "🛸 Everything is ready for the project"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR) $(MKDFLAGS) $(dir $@)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@echo "$(OK) Compiled $<"

$(BANNER):
	@echo " ______  __  __  __  __      ______   "
	@echo "/\\  == \\/\\ \\_\\ \\/\\ \\/\\ \\    /\\  __ \\  "
	@echo "\\ \\  _-/\\ \\  __ \\ \\ \\ \\ \\___\\ \\ \\/\\ \\ "
	@echo " \\ \\_\\   \\ \\_\\ \\_\\ \\_\\ \\_____\\ \\_____\\"
	@echo "  \\/_/    \\/_/\\/_/\\/_/\\/_____/\\/_____/"
	@echo "$(LOCAL) | $(NAME) $(VERSION)"
	@echo "$(MAIL)"

clean:
	@$(REMOVE) $(RMFLAGS) $(OBJ_DIR)
	@echo "$(CLEAN) Clean objects"

fclean: clean
	@$(REMOVE) $(RMFLAGS) $(BIN_DIR)
	@echo "$(CLEAN) Clean executable"

re: fclean all

.PHONY: all clean fclean re
