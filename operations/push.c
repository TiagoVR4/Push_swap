/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:42:14 by coder             #+#    #+#             */
/*   Updated: 2025/03/06 10:44:11 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_node **src, t_node **dest)
{
	t_node	*first;
	t_node	*second;
  
	if (!*src)
		return ;
	first = *src;
	second = first->next;
	if(first->next != first)
	{
		first->prev->next = second;
		second->prev = first->prev;
		*src = second;
	}
	else
		*src = NULL;
	add_top(first, dest);
}

void	add_top(t_node *src, t_node **dest)
{
	t_node	*first;
	t_node	*dest_first;

	first = src;
	dest_first = *dest;
	if (dest_first == NULL)
	{
		*dest = first;
		first->next = first;
		first->prev = first;
	}
	else
	{
		first->next = dest_first;
		first->prev = dest_first->prev;
		dest_first->prev->next = first;
		dest_first->prev = first;
		*dest = first;
	}
}

void	call_push(t_node **stack_a, t_node **stack_b, char flag)
{
	if (flag == 'a')
	{
		push(stack_b,stack_a);
		ft_printf("pa\n");
	}
	else if (flag == 'b')
	{
		push(stack_a, stack_b);
		ft_printf("pb\n");
	}
	else
		ft_printf("invalid flag\n");
}