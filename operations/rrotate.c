/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:13:07 by coder             #+#    #+#             */
/*   Updated: 2025/03/02 17:10:45 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrotate(t_node **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	*stack = (*stack)->prev;
}

void	call_rrotate(t_node **stack_a, t_node **stack_b, char flag)
{
	if (flag == 'a')
	{
		swap(stack_a);
		ft_printf("rra\n");
	}
	else if (flag == 'b')
	{
		swap(stack_b);
		ft_printf("rrb\n");
	}
	else if (flag == 'r')
	{
		swap(stack_a);
		swap(stack_b);
		ft_printf("rrr\n");
	}
	else
		ft_printf("invalid flag\n");
}
