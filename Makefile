# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 23:05:17 by mel-yous          #+#    #+#              #
#    Updated: 2023/01/01 18:38:45 by mel-yous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server client

SRCS = server.c client.c
BSRCS = server_bonus.c client_bonus.c

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

LIBFT = libft/libft.a
UTILS = minitalk_utils.c
BUTILS = minitalk_utils_bonus.c
ACKNOW = acknowledge_bonus.c

CC = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

bonus: server_bonus client_bonus

server: server.o
	make -C libft/
	$(CC) -o $@ $< $(LIBFT) $(UTILS)

client: client.o
	$(CC) -o $@ $< $(LIBFT) $(UTILS)

server_bonus: server_bonus.o
	make -C libft/
	$(CC) -o $@ $< $(LIBFT) $(BUTILS) $(ACKNOW)

client_bonus: client_bonus.o
	$(CC) -o $@ $< $(LIBFT) $(BUTILS)

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $<

%_bonus.o: %_bonus.c minitalk_bonus.h
	$(CC) $(CFLAGS) -c $<

clean:
	make -C libft/ clean
	rm -rf $(OBJS) $(BOBJS)

fclean: clean
	make -C libft/ fclean
	rm -rf client server client_bonus server_bonus

re: fclean all

.PHONY: all bonus clean fclean re