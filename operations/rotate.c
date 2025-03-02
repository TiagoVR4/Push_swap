/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:19:48 by coder             #+#    #+#             */
/*   Updated: 2025/03/02 17:08:51 by tiagalex         ###   ########.fr       */
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
		swap(stack_a);
		ft_printf("ra\n");
	}
	else if (flag == 'b')
	{
		swap(stack_b);
		ft_printf("rb\n");
	}
	else if (flag == 'r')
	{
		swap(stack_a);
		swap(stack_b);
		ft_printf("rr\n");
	}
	else
		ft_printf("invalid flag\n");
}
