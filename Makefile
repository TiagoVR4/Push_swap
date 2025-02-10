# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 16:21:20 by tiagalex          #+#    #+#              #
#    Updated: 2025/02/10 13:47:38 by tiagalex         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE	= make -C

NAME	= push_swap

LIBS_PATH = lib
LIBFT_PATH = $(LIBS_PATH)/libft
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

$(NAME): $(OBJ) $(LIBFT_ARC)
	$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C ./libft

get_libft:
	@echo "Getting Libft"
	git clone git@github.com:TiagoVR4/libft.git $(LIBFT_PATH)
	@echo "Done downloading Libft"

$(LIBFT_ARC):
	$(MAKE) $(LIBFT_PATH) bonus

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	$(MAKE) $(LIBFT_PATH) fclean

libclean: fclean
	rm -fr $(LIBS_PATH)
	
re: fclean all

.PHONY: all clean fclean re