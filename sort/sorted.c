/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:48:40 by tiagalex          #+#    #+#             */
/*   Updated: 2025/03/26 12:03:04 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sorted(t_node **stack)
{
	t_node	*first;
	t_node	*content;

	first = *stack;
	content = *stack;
	if (!*stack || (*stack)->next == first)
		return (1);
	while (first != content->next)
	{
		if (content->value > content->next->value)
			return (0);
		content = content->next;
	}
	return (1);
}
