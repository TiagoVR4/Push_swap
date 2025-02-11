# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 16:21:20 by tiagalex          #+#    #+#              #
#    Updated: 2025/02/11 15:46:01 by tiagalex         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE	= make -C

NAME	= push_swap

LIBFT_PATH = libft
LIBFT_ARC = $(LIBFT_PATH)/libft.a

CC =	cc
CFLAGS = -Wall -Wextra -Werror

SRC = create_stack.c

OBJ = $(SRC:.c=.o)

all: deps $(NAME)

deps:
	@if test ! -d "$(LIBFT_PATH)"; then make get_libft; \
		else echo "[libft] folder found 🖔"; fi
	@echo " [$(GRN)Nothing to be done!$(D)]"

$(NAME): $(LIBFT_ARC) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_ARC) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

get_libft:
	@echo "Getting Libft"
	git clone git@github.com:TiagoVR4/libft.git $(LIBFT_PATH)
	@echo "Done downloading Libft"

$(LIBFT_ARC): 
	$(MAKE) $(LIBFT_PATH) all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	$(MAKE) $(LIBFT_PATH) fclean

libclean: fclean
	rm -fr $(LIBFT_PATH)
	
re: fclean all

.PHONY: all clean fclean re