/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   bench_utils.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: nmokashi <nmokashi@student.42.berlin.de>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/11 14:34:23 by nmokashi         #+#    #+#              */
/*   Updated: 2026/08/11 17:29:36 by nmokashi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_counters_ra(t_stack *stack)
{
	t_bench	*b;

	b = &stack->bench;
	print_str_fd(2, "\n");
	print_str_fd(2, "rb: ");
	print_nbr_fd(2, b->rb);
	print_str_fd(2, " rr: ");
	print_nbr_fd(2, b->rr);
	print_str_fd(2, " rra: ");
	print_nbr_fd(2, b->rra);
	print_str_fd(2, " rrb: ");
	print_nbr_fd(2, b->rrb);
	print_str_fd(2, " rrr: ");
	print_nbr_fd(2, b->rrr);
	print_str_fd(2, "\n");
}

static void	print_counters_sa(t_stack *stack)
{
	t_bench	*b;

	b = &stack->bench;
	print_str_fd(2, "\n");
	print_str_fd(2, "sa: ");
	print_nbr_fd(2, b->sa);
	print_str_fd(2, " sb: ");
	print_nbr_fd(2, b->sb);
	print_str_fd(2, " ss: ");
	print_nbr_fd(2, b->ss);
	print_str_fd(2, " pa: ");
	print_nbr_fd(2, b->pa);
	print_str_fd(2, " pb: ");
	print_nbr_fd(2, b->pb);
	print_str_fd(2, " ra: ");
	print_nbr_fd(2, b->ra);
}

static void	print_strategy(t_flag *flag)
{
	if (flag->algo_mode == 0)
		print_str_fd(2, "Simple ");
	else if (flag->algo_mode == 1)
		print_str_fd(2, "Medium ");
	else if (flag->algo_mode == 2)
		print_str_fd(2, "Complex ");
	else
		print_str_fd(2, "Adaptive ");
}

static void	print_complexity(t_stack *stack, t_flag *flag)
{
	if (flag->algo_mode == 3)
	{
		if (stack->bench.disorder <= 20)
			print_str_fd(2, "(O(n^2))\n");
		else if (stack->bench.disorder <= 50)
			print_str_fd(2, "(O(n*sqrt(n)))\n");
		else if (stack->bench.disorder <= 100)
			print_str_fd(2, "(O(n log n))\n");
	}
	else
	{
		if (flag->algo_mode == 0)
			print_str_fd(2, "(O(n^2))\n");
		else if (flag->algo_mode == 1)
			print_str_fd(2, "(O(n*sqrt(n)))\n");
		else if (flag->algo_mode == 2)
			print_str_fd(2, "(O(n log n))\n");
	}
}

void	print_bench(t_stack *stack, t_flag *flag)
{
	t_bench	*b;
	int		total;

	b = &stack->bench;
	total = b->sa + b->sb + b->ss
		+b->pa + b->pb
		+b->ra + b->rb + b->rr
		+b->rra + b->rrb + b->rrr;
	print_str_fd(2, "[bench] Disorder: ");
	print_float2_fd(2, stack->bench.disorder);
	print_str_fd(2, "%\n");
	print_str_fd(2, "[bench] Strategy: ");
	print_strategy(flag);
	print_complexity(stack, flag);
	print_str_fd(2, "[bench] Total operations: ");
	print_nbr_fd(2, total);
	print_counters_sa(stack);
	print_counters_ra(stack);
	print_str_fd(2, "\n");
}
