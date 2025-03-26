/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:44:02 by tiagalex          #+#    #+#             */
/*   Updated: 2025/03/26 12:00:18 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!*stack || !(*stack)->next || (*stack)->next == *stack)
		return ;
	first = *stack;
	second = first->next;
	first->prev->next = second;
	second->next->prev = first;
	first->next = second->next;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	*stack = second;
}

void	call_swap(t_node **stack_a, t_node **stack_b, char flag)
{
	if (flag == 'a')
	{
		swap(stack_a);
		ft_printf("sa\n");
	}
	else if (flag == 'b')
	{
		swap(stack_b);
		ft_printf("sb\n");
	}
	else if (flag == 's')
	{
		swap(stack_a);
		swap(stack_b);
		ft_printf("ss\n");
	}
	else
		ft_printf("invalid flag\n");
}
