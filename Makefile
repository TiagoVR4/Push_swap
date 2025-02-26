# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 16:21:20 by tiagalex          #+#    #+#              #
#    Updated: 2025/02/26 17:32:25 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE	= make -C

NAME	= push_swap

LIBFT_PATH = libft
LIBFT_ARC = $(LIBFT_PATH)/libft.a

FT_PRINTF_PATH = ft_printf
FT_PRINTF_ARC = $(FT_PRINTF_PATH)/libftprintf.a

SRC = create_stack.c operations/swap.c operations/push.c operations/rotate.c \
	operations/rrotate.c

OBJ = $(SRC:.c=.o)

#------------------------------------------------------------------------------#
#								COMPILATION									   #
#------------------------------------------------------------------------------#

CC =	cc
CFLAGS = -Wall -Wextra -Werror

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

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) $(LIBFT_PATH) fclean
	@$(MAKE) $(FT_PRINTF_PATH) fclean

libclean: fclean
	@rm -fr $(LIBFT_PATH)

printfclean: fclean
	@rm -fr $(FT_PRINTF_PATH)
	
re: fclean all

.PHONY: all clean fclean re