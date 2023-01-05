# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 20:18:10 by mel-yous          #+#    #+#              #
#    Updated: 2023/01/01 04:16:39 by mel-yous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_atoi.c ft_bzero.c ft_isdigit.c ft_memcpy.c ft_putstr_fd.c ft_strdup.c\
ft_strjoin.c ft_strlen.c ft_substr.c ft_putchar_fd.c ft_putnbr_fd.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $<

clean:	
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)
re : fclean all
