/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagvr <tiagvr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:32:50 by tiagalex          #+#    #+#             */
/*   Updated: 2025/03/14 12:10:51 by tiagvr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void	sort_b(t_node **stack_a, t_node **stack_b, int pos, int target)
{
	int	rot_a;
	int	rot_b;

	rot_a = index_top(stack_a, pos);
	rot_b = 0;
	if (*stack_b == NULL)
	{
		execute_rotations(stack_a, stack_b, rot_a);
	}
	else
	{
		rot_b = calculate_rot_b(stack_b, target);
		combine_rotations(stack_a, stack_b, rot_a, rot_b);
		call_push(stack_a, stack_b, 'b');
	}

}

int	calculate_rot_b(t_node **stack_b, int target)
{
	t_node	*temp;
	int		rot_b;
	int		pos_target;

	temp = *stack_b;
	rot_b = 0;
	pos_target = 0;
	while (pos_target < stack_size(stack_b))
	{
		if (temp->index < target)
		{
			rot_b = index_top(stack_b, pos_target);
			return (rot_b);
		}
		else
		{
			pos_target++;
			temp = temp->next;
		}
	}
	rot_b = index_top(stack_b, pos_target);
	return (rot_b);
}

void	combine_rotations(t_node **stack_a, t_node **stack_b, int rot_a, int rot_b)
{
	int	min;

	if (rot_a > 0 && rot_b > 0)
	{
		min = rot_a;
		if (rot_b < rot_a)
			min = rot_b;
		select_rotation(stack_a, stack_b, min, 'r');
		rot_a = rot_a - min;
		rot_b = rot_b - min;
	}
	else if( rot_a < 0 && rot_b < 0)
	{
		min = -rot_a;
		if (rot_b < rot_a)
			min = -rot_b;
		select_rotation(stack_a, stack_b, min, 'v');
		rot_a = rot_a + min;
		rot_b = rot_b + min;
	}
	complete_rotations(stack_a, stack_b, rot_a, rot_b);
}
void	select_rotation(t_node **stack_a, t_node **stack_b, int	min, char flag)
{
	while (min > 0)
		{
			if (flag == 'r')
				call_rotate(stack_a, stack_b, 'r');
			else
				call_rrotate(stack_a, stack_b, 'r');
			min--;
		}
}

void	complete_rotations(t_node **stack_a, t_node **stack_b, int rot_a, int rot_b)
{
	while (rot_a > 0)
	{
		call_rotate(stack_a, NULL, 'a');
		rot_a--;
	}
	while (rot_b > 0)
	{
		call_rotate(NULL, stack_b, 'b');
		rot_b--;
	}
	while (rot_a < 0)
	{
		call_rrotate(stack_a, NULL, 'a');
		rot_a++;
	}
	while(rot_b < 0)
	{
		call_rrotate(NULL, stack_b, 'b');
		rot_b++;
	}
}
