# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/28 23:13:38 by myli-pen          #+#    #+#              #
#    Updated: 2025/06/29 09:08:51 by myli-pen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL = all
NAME = program
CC = cc
CFLAGS = -Wall -Wextra -Werror
MAKEFLAGS += --no-print-directory
DIR_SRC = src
DIR_OBJ = obj
DIR_DEP = dep

SRCS = $(addprefix $(DIR_SRC)/, \
		get_next_line_bonus.c get_next_line_utils_bonus.c)
OBJS = $(patsubst $(DIR_SRC)/%.c, $(DIR_OBJ)/%.o, $(SRCS))
DEPS = $(patsubst $(DIR_SRC)/%.c, $(DIR_DEP)/%.d, $(SRCS))

all: $(DIR_OBJ) $(NAME)

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ) $(DIR_DEP)

$(NAME): $(OBJS)
	@$(CC) -g $(CFLAGS) $(OBJS) main.c -o $(NAME)
	@echo "\033[1;33m [✔] $(NAME) created \033[0m\n"
	./$(NAME)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@ \
	-MMD -MP -MF $(patsubst $(DIR_OBJ)/%.o, $(DIR_DEP)/%.d, $@)
	@echo "\033[1;32m [+]\033[0m compiling $@"

clean:
	@rm -rf $(DIR_OBJ) $(DIR_DEP)
	@echo "\033[1;31m [-]\033[0m removed ./obj/"
	@echo "\033[1;31m [-]\033[0m removed ./dep/"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[1;31m [-]\033[0m removed $(NAME)"

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJS) $(DEPS)

-include $(DEPS)
