/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:32:46 by tiagalex          #+#    #+#             */
/*   Updated: 2025/02/25 11:25:53 by tiagalex         ###   ########.fr       */
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

#endif