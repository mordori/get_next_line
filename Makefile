# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/28 23:13:38 by myli-pen          #+#    #+#              #
#    Updated: 2025/06/29 16:00:52 by myli-pen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL = all
NAME = program
CC = cc
CFLAGS = -Wall -Wextra -Werror
MAKEFLAGS += --no-print-directory
DIR_SRC = src
BUFFER_SIZE ?= 1024
FD_MAX ?= 5

SRCS = $(addprefix $(DIR_SRC)/, \
		get_next_line_bonus.c get_next_line_utils_bonus.c)

all: $(NAME)

$(NAME): clean
	@$(CC) -g $(CFLAGS) $(SRCS) main.c -o $(NAME) \
	-D BUFFER_SIZE=$(BUFFER_SIZE) -D FD_MAX=$(FD_MAX)
	@echo "\033[1;33m [✔] $(NAME) created \033[0m\n"
	./$(NAME)

clean:
	@rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
