/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:42:06 by tiagalex          #+#    #+#             */
/*   Updated: 2025/02/25 18:02:04 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_parsing(t_node **stack_a, int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc < 2)
		return (0);
	if (argc == 2 && need_split(argv[1] == 0))
	{
		char	*clone;

		clone = argv[1];
		stack_a = ft_split(argv[1], " ");
		while (stack_a[i] <= argc)
		{
			if (is_number())
			{
				write(2, "not a number", 12);
				free_stack(stack_a);
				return (0);
			}
			 = ft_atoi(stack_a[i]);
		}
	}
}