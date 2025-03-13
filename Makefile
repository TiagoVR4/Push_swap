# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiagvr <tiagvr@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 16:21:20 by tiagalex          #+#    #+#              #
#    Updated: 2025/03/13 12:48:05 by tiagvr           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE	= make -C

NAME	= push_swap

LIBFT_PATH = libft
LIBFT_ARC = $(LIBFT_PATH)/libft.a

FT_PRINTF_PATH = ft_printf
FT_PRINTF_ARC = $(FT_PRINTF_PATH)/libftprintf.a

SRC =  push_swap.c \
		create_stack.c \
		ft_parsing.c \
		operations/swap.c \
		operations/push.c \
		operations/rotate.c \
		operations/rrotate.c \
		sort/mini_sort.c \
		sort/medium_sort.c \
		sort/turk_sort.c \
		sort/sort_b.c \
		sort/sorted.c \

OBJ = $(SRC:.c=.o)

#------------------------------------------------------------------------------#
#								COMPILATION									   #
#------------------------------------------------------------------------------#

CC =	cc
CFLAGS = -Wall -Wextra -Werror -g

all: deps $(NAME)

deps: get_libft get_ft_printf
	@echo "[$(GRN)Nothing to be done!$(D)]"

get_libft:
	@if [ -d "$(LIBFT_PATH)" ]; then \
		echo "[libft] folder found 🖔"; \
	else \
		echo "Getting Libft"; \
		git clone https://github.com/TiagoVR4/libft.git $(LIBFT_PATH); \
		echo "Done downloading Libft"; \
	fi

get_ft_printf:
	@if [ -d "$(FT_PRINTF_PATH)" ]; then \
		echo "[ft_printf] folder found 🖔"; \
	else \
		echo "Getting ft_printf"; \
		git clone https://github.com/TiagoVR4/ft_printf.git $(FT_PRINTF_PATH); \
		echo "Done downloading ft_printf"; \
	fi

$(NAME): $(LIBFT_ARC) $(FT_PRINTF_ARC) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_ARC) $(FT_PRINTF_ARC) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@


$(LIBFT_ARC):
	@$(MAKE) $(LIBFT_PATH) all

$(FT_PRINTF_ARC):
	@$(MAKE) $(FT_PRINTF_PATH) all

#------------------------------------------------------------------------------#
#								CLEANING RULES									   #
#------------------------------------------------------------------------------#

clean:
	@rm -f $(OBJ)
	@echo "[All .o files clean! 🖔]";

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) $(LIBFT_PATH) fclean
	@$(MAKE) $(FT_PRINTF_PATH) fclean
	@echo "[All files clean! 🖔]";

libclean: fclean
	@rm -fr $(LIBFT_PATH)

printfclean: fclean
	@rm -fr $(FT_PRINTF_PATH)
	
re: fclean all
	@echo "[All files are re-compiled! 🖔]";

.PHONY: all clean fclean re