/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:42:06 by tiagalex          #+#    #+#             */
/*   Updated: 2025/02/26 17:52:38 by coder            ###   ########.fr       */
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
		char	**str;

		clone = argv[1];
		**str = ft_split(clone, " ");
		while (i < argc)
		{
			if (is_not_number(str[i]) || is_not_int(str[i]))
			{
				write(2, "not a int", 9);
				free_stack(stack_a);
				return (0);
			}
			if (duplicate(str))
			{
				write(2, "is Duplicated", 13);
				free_stack(stack_a);
				return (0);
			}
			i++;
		}
	}
}

int	is_not_number(char	*str)
{
	int	i;
	
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
	}
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	is_not_int(char *str)
{
	long 	n;

	n = ft_atol(str);
	if (n > INT_MAX || n < INT_MIN)
		return (1);
	return (0);
}

int	duplicate(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		j = i + 1;
		while (str[j] != '\0')
		{
			if(str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}