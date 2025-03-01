/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:32:46 by tiagalex          #+#    #+#             */
/*   Updated: 2025/02/27 14:53:41 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <limits.h>

typedef struct	t_node
{
	int				value;
	int				index;
	int				chunk;
	struct t_node	*next;
	struct t_node	*prev;
}					t_node;

//Funtions
t_node	*new_node(char *str);

void	add_node(t_node **stack, char *new);
void	free_stack(t_node **stack);
void	swap(t_node **stack);
void    push(t_node **src, t_node **dest);
void    rotate(t_node **stack);
void	rrotate(t_node **stack);
void	push_swap(t_node stack_a, t_node stack_b);

int		ft_parsing(t_node **stack, int argc, char **argv);
int		build_stack(t_node **stack, char **array, int i);
int		contains_space(char *str);
int		invalid_number(char *str);
int		duplicate(t_node **stack);
int 	main(int argc, char **argv);

#endif