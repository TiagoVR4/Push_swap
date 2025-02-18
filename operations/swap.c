/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:44:02 by tiagalex          #+#    #+#             */
/*   Updated: 2025/02/18 16:19:02 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_node **stack)
{
    t_node  *first;
    t_node  *second;
    int temp_index;

    first = *stack;
    second = first->next;
    first->prev->next = second;
    second->next->prev = first;
    first->next = second->next;
    second->prev = first->prev;
    second->next = first;
    first->prev = second;
    stack = second;
    
    temp_index = first->index;
    first->index = second->index;
    second->index = temp_index;
}