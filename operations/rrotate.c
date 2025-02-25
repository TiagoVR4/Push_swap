/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:13:07 by coder             #+#    #+#             */
/*   Updated: 2025/02/25 11:14:38 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrotate(t_node **stack)
{
	if (!&stack || !(*stack)->next)
		return ;
	*stack = (*stack)->prev;
}
