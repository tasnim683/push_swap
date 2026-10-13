/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasnimo <tasnimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 17:10:15 by nmokashi          #+#    #+#             */
/*   Updated: 2026/08/13 14:35:45 by tasnimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

static int	run_push_swap(char **values, int count, t_flag *flags)
{
	int		i;
	t_stack	stack;
	t_bench	bench;

	if (!init_stack(&stack.a, &stack.b, count))
		return (1);
	init_bench(&bench);
	stack.size_a = count;
	stack.size_b = 0;
	stack.bench = bench;
	i = 0;
	while (i < count)
	{
		stack.a[i] = ft_atoi(values[i]);
		i++;
	}
	check_duplicates(stack.a, stack.size_a);
	adaptive_sort(&stack, flags);
	if (flags->bench)
		print_bench(&stack, flags);
	free(stack.a);
	free(stack.b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_flag	flags;
	char	**values;
	int		count;

	if (argc == 1)
		return (0);
	parse_options(argc, argv, &flags);
	if (flags.value_start >= argc)
		return (0);
	values = get_values(argc, argv, &flags, &count);
	if (!values)
		return (1);
	validate_args(values);
	run_push_swap(values, count, &flags);
	if (values != &argv[flags.value_start])
	{
		while (count--)
			free(values[count]);
		free(values);
	}
	return (0);
}
