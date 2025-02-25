/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:42:14 by coder             #+#    #+#             */
/*   Updated: 2025/02/25 11:18:23 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_node **src, t_node **dest)
{
	t_node	*first;
	t_node	*second;
	t_node	*dest_first;
  
	if (!*src)
		return ;
	first = *src;
	second = first->next;
	dest_first = *dest;
	if(first->next != first)
	{
		first->prev->next = second;
		second->prev = first->prev;
		*src = second;
	}
	else
		*src = NULL;
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