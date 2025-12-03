# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/29 12:17:09 by mhidani           #+#    #+#              #
#    Updated: 2025/12/03 00:12:24 by mhidani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
LOCAL		= 42sp.org.br
SOCIAL		= linkedin.com/in/mauricio-hidani
REPOSITORY	= github.com/mauricioHidani
VERSION		= 1.0.0v

CC			= cc
CFLAGS		= -g -Wall -Wextra -Werror
AR			= ar
ARFLAGS		= -rcs
VALGRIND	= valgrind
MKDIR		= mkdir -p
RMDIR		= rm -rf

SRCS_DIR	= srcs/
INCS_DIR	= includes/
OBJS_DIR	= objs/
SLIB_DIR	= libs/
BIN_DIR		= bin/

SRCS		= $(wildcard $(SRCS_DIR)*.c)
OBJS		= $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

RST			:= \033[0m# Reset
C01			:= \033[38;5;27m# Blue
C02			:= \033[38;5;63m# Purplish blue
C03			:= \033[38;5;99m# Purple
C04			:= \033[38;5;135m# Magenta
C05			:= \033[38;5;171m# Pink
C06			:= \033[38;5;207m# Light pink
C07			:= \033[38;5;213m# Deep pink
C08			:= \033[38;5;219m# Pastel pink
C09			:= \033[38;5;215m# Soft orange
C10			:= \033[38;5;208m# Bright orange

all: banner $(NAME)

$(NAME): $(BIN_DIR)
	$(CC) $(CFLAGS) -I$(INCS_DIR) $(SRCS) -o $(BIN_DIR)$@

$(SLIB_DIR):
	@$(MKDIR) $@
	@echo -n "$(C06)make directory $@$(RST)"

$(OBJS_DIR):
	@$(MKDIR) $@
	@echo -n "$(C06)make directory $@$(RST)"

$(BIN_DIR):
	@$(MKDIR) $@
	@echo -n "$(C06)make directory $@$(RST)"


# Basic Commands ---------------------------------------------------------------

clean:
	@echo "$(C07)🧹 Clean$(RST)"
	@$(RM) $(OBJS)
	@echo "  $(C08)🧽 deleted objects file$(RST)"

fclean: clean
	@echo "$(C07)🧹 Full Clean$(RST)"
	@$(RMDIR) $(OBJS_DIR)
	@echo "  $(C08)🧽 deleted object's directory$(RST)"
	@$(RMDIR) $(SLIB_DIR)
	@echo "  $(C08)🧽 deleted static lib's directory$(RST)"
	@$(RMDIR) $(BIN_DIR)
	@echo "  $(C08)🧽 deleted binary's directory$(RST)"

re: fclean all

banner:
	@echo ""
	@echo "$(C01)📍42School - $(LOCAL)$(RST)"
	@echo "$(C01)░█▀█░█░█░▀█▀░█░░░█▀█░█▀▀░█▀█░█▀█░█░█░█▀▀░█▀▄░█▀▀ $(RST)";
	@echo "$(C02)░█▀▀░█▀█░░█░░█░░░█░█░▀▀█░█░█░█▀▀░█▀█░█▀▀░█▀▄░▀▀█ $(RST)";
	@echo "$(C03)░▀░░░▀░▀░▀▀▀░▀▀▀░▀▀▀░▀▀▀░▀▀▀░▀░░░▀░▀░▀▀▀░▀░▀░▀▀▀ $(RST)";
	@echo "$(C04)$(VERSION) - common-core/milestone3$(RST)"
	@echo "$(C05)$(SOCIAL) | $(REPOSITORY)$(RST)"
	@echo ""

.PHONY: all clean fclean re banner
