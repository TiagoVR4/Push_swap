/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:19:48 by coder             #+#    #+#             */
/*   Updated: 2025/02/24 18:08:39 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    rotate(t_node **stack)
{
    t_node  *first;
    t_node  *last;
    
    first = *stack;
    last = (*stack)->prev;
    *stack= first->next;
    (*stack)->prev = last;
    last->next = *stack;
    first->next = NULL;
    first->prev = NULL;
}
