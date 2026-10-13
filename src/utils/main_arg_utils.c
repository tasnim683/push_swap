/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_arg_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasnimo <tasnimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 20:07:51 by nmokashi          #+#    #+#             */
/*   Updated: 2026/08/13 13:23:02 by tasnimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_mode(char *arg)
{
	if (!ft_strcmp(arg, "--simple"))
		return (MODE_SIMPLE);
	if (!ft_strcmp(arg, "--medium"))
		return (MODE_MEDIUM);
	if (!ft_strcmp(arg, "--complex"))
		return (MODE_COMPLEX);
	if (!ft_strcmp(arg, "--adaptive"))
		return (MODE_ADAPTIVE);
	return (-1);
}

static void	init_flags(t_flag *flags)
{
	flags->algo_mode = MODE_ADAPTIVE;
	flags->bench = 0;
	flags->value_start = 1;
	flags->print_op = 1;
}

void	init_bench(t_bench *bench)
{
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->disorder = 0.0;
}

void	parse_options(int argc, char **argv, t_flag *flags)
{
	int	mode;

	init_flags(flags);
	if (flags->value_start < argc
		&& !ft_strcmp(argv[flags->value_start], "--bench"))
	{
		flags->bench = 1;
		flags->value_start++;
	}
	if (flags->value_start < argc)
	{
		mode = parse_mode(argv[flags->value_start]);
		if (mode >= 0)
		{
			flags->algo_mode = mode;
			flags->value_start++;
		}
	}
}

int	init_stack(int **a, int **b, int size)
{
	*a = malloc(sizeof(int) * size);
	*b = malloc(sizeof(int) * size);
	if (!*a || !*b)
	{
		free(*a);
		free(*b);
		return (0);
	}
	return (1);
}
