/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasnimo <tasnimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 17:26:26 by nmokashi          #+#    #+#             */
/*   Updated: 2026/08/13 13:51:28 by tasnimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int *a, int size_a)
{
	int	i;

	i = 0;
	while (i < size_a - 1)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

char	**get_values(int argc, char **argv, t_flag *flags, int *count)
{
	char	**values;
	int		i;

	if (argc - flags->value_start == 1)
	{
		i = 0;
		while (argv[flags->value_start][i])
		{
			if (argv[flags->value_start][i] == ' ')
			{
				values = ft_split(argv[flags->value_start], ' ');
				if (!values)
					return (NULL);
				*count = 0;
				while (values[*count])
					(*count)++;
				return (values);
			}
			i++;
		}
	}
	*count = argc - flags->value_start;
	return (&argv[flags->value_start]);
}
