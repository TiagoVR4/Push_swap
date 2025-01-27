# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 16:21:20 by tiagalex          #+#    #+#              #
#    Updated: 2025/01/27 13:50:01 by tiagalex         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libpush_swap.a

LIBFT = ./libft/libft.a


CC = cc
CFLAGS = -g -Wall -Wextra -Werror

SRC = 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	ar -rcs $(NAME) $(LIBFT) $(OBJ)

%.o: %.c
	$(cc) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C ./libft

clean:
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re