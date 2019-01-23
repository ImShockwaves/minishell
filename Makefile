# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 15:38:06 by ccharrie          #+#    #+#              #
#    Updated: 2018/01/31 13:43:50 by ccharrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
RM = rm -rf
NAME = minishell
FLAGS = -Wall -Werror -Wextra
SRCS = moreenv.c lstbasic.c cd.c doer.c complft.c display.c main.c envft.c checker.c
OBJS = $(SRCS:.c=.o)
MAKEFLAGS = s

.PHONY: all clean fclean

all: $(NAME)

$(NAME): $(OBJS)
		@make -C libft/
		@echo "\033[32;1mLibrary compilation done\033[0m"

		
		@$(CC) -o $(NAME) $(OBJS) -L libft/ -lft
		@echo "\033[36;1mProject compilation done\033[0m"

		@$(CC) -c $(FLAGS) $(SRCS) -I libft/

clean:
		@make clean -C libft/
	
		@$(RM) $(OBJS)

fclean: clean
		@make fclean -C libft/
	
		@$(RM) $(NAME)

		@echo "\033[31;1mClean done\033[0m"

re: fclean all
