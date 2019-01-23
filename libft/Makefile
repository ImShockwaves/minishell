# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 14:56:40 by ccharrie          #+#    #+#              #
#    Updated: 2018/02/05 16:05:27 by ccharrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Werror -Wextra
NAME = libft.a
SRCS = ft_del2tab.c ft_tablen.c ft_2strdel.c ft_strjoinndels1.c ft_resizetab.c ft_puttab.c ft_splitwhitespaces.c get_next_line.c ft_del2dtab.c ft_strjoinnfree.c ft_atoi.c ft_memccpy.c ft_putendl.c ft_strcmp.c ft_strlen.c ft_strrchr.c ft_bzero.c ft_memchr.c ft_putendl_fd.c ft_strcpy.c ft_strmap.c ft_strsplit.c ft_isalnum.c ft_memcmp.c ft_putnbr.c ft_strdel.c ft_strmapi.c ft_strstr.c ft_isalpha.c ft_memcpy.c ft_putnbr_fd.c ft_strdup.c ft_strncat.c ft_strsub.c ft_isascii.c ft_memdel.c ft_putstr.c ft_strequ.c ft_strncmp.c ft_strtrim.c ft_isdigit.c ft_memmove.c ft_putstr_fd.c ft_striter.c ft_strncpy.c ft_tolower.c ft_isprint.c ft_memset.c ft_strcat.c ft_striteri.c ft_strnequ.c ft_toupper.c ft_itoa.c ft_putchar.c ft_strchr.c ft_strjoin.c ft_strnew.c ft_memalloc.c ft_putchar_fd.c ft_strclr.c ft_strlcat.c ft_strnstr.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_putnbrbase.c ft_sqrt.c ft_recursive_pow.c ft_lstaddend.c ft_putlst.c ft_putcolor.c ft_putformat.c ft_putcformat.c
OBJECTS = $(SRCS:.c=.o)
RM = rm -rf
OPTIONS = -c 

all: $(NAME)

$(NAME):
				@$(CC) $(FLAGS) $(OPTIONS) $(SRCS)
				@ar rc $(NAME) $(OBJECTS)
				@ranlib $(NAME)	

clean:
	  	 @$(RM) $(OBJECTS)

fclean: clean
	     @$(RM) $(NAME)

re: fclean all
