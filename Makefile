# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 16:21:20 by tiagalex          #+#    #+#              #
#    Updated: 2025/02/12 12:01:34 by tiagalex         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE	= make -C

NAME	= push_swap

LIBFT_PATH = libft
LIBFT_ARC = $(LIBFT_PATH)/libft.a

FT_PRINTF_PATH = ft_printf
FT_PRINTF_ARC = $(FT_PRINTF_PATH)/libftprintf.a

SRC = create_stack.c

OBJ = $(SRC:.c=.o)

#------------------------------------------------------------------------------#
#								COMPILATION									   #
#------------------------------------------------------------------------------#

CC =	cc
CFLAGS = -Wall -Wextra -Werror

all: deps $(NAME)

deps:
	@if test ! -d "$(LIBFT_PATH)"; then make get_libft; \
		else echo "[libft] folder found 🖔"; fi
	@if test ! -d "$(FT_PRINTF_PATH)"; then make get_ft_printf; \
		else echo "[ft_printf] folder found 🖔"; fi
	@echo " [$(GRN)Nothing to be done!$(D)]"

$(NAME): $(LIBFT_ARC) $(FT_PRINTF_ARC) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_ARC) $(FT_PRINTF_ARC) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

get_libft:
	@echo "Getting Libft"
	git clone git@github.com:TiagoVR4/libft.git $(LIBFT_PATH)
	@echo "Done downloading Libft"

get_ft_printf:
	@echo "Getting ft_printf"
	git clone git@github.com:TiagoVR4/ft_printf.git $(FT_PRINTF_PATH)
	@echo "Done downloading ft_printf"

$(LIBFT_ARC): 
	$(MAKE) $(LIBFT_PATH) all

$(FT_PRINTF_ARC): 
	$(MAKE) $(FT_PRINTF_PATH) all

#------------------------------------------------------------------------------#
#								CLEANING RULES									   #
#------------------------------------------------------------------------------#

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	$(MAKE) $(LIBFT_PATH) fclean
	$(MAKE) $(FT_PRINTF_PATH) fclean

libclean: fclean
	rm -fr $(LIBFT_PATH)

printfclean: fclean
	rm -fr $(FT_PRINTF_PATH)
	
re: fclean all

.PHONY: all clean fclean re