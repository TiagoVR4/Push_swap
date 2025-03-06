/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:32:46 by tiagalex          #+#    #+#             */
/*   Updated: 2025/03/06 11:33:13 by tiagalex         ###   ########.fr       */
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
void	call_swap(t_node **stack_a, t_node **stack_b, char flag);
void	call_push(t_node **stack_a, t_node **stack_b, char flag);
void	add_top(t_node *src, t_node **dest);
void	call_rotate(t_node **stack_a, t_node **stack_b, char flag);
void	call_rrotate(t_node **stack_a, t_node **stack_b, char flag);
void	push_swap(t_node **stack_a, t_node **stack_b);
void	mini_sort(t_node **stack);
void	medium_sort(t_node **stack_a, t_node **stack_b);
void	set_index(t_node **stack);

int		ft_parsing(t_node **stack, int argc, char **argv);
int		build_stack(t_node **stack, char **array, int i);
int		stack_size(t_node **stack);
int		contains_space(char *str);
int		invalid_number(char *str);
int		duplicate(t_node **stack);
int		sorted(t_node **stack);
int 	main(int argc, char **argv);

#endif