/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:19:48 by coder             #+#    #+#             */
/*   Updated: 2025/03/06 10:44:39 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_node **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
}

void	call_rotate(t_node **stack_a, t_node **stack_b, char flag)
{
	if (flag == 'a')
	{
		rotate(stack_a);
		ft_printf("ra\n");
	}
	else if (flag == 'b')
	{
		rotate(stack_b);
		ft_printf("rb\n");
	}
	else if (flag == 'r')
	{
		rotate(stack_a);
		rotate(stack_b);
		ft_printf("rr\n");
	}
	else
		ft_printf("invalid flag\n");
}
