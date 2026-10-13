/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   adaptive.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: nmokashi <nmokashi@student.42.berlin.de>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/06 17:23:20 by nmokashi         #+#    #+#              */
/*   Updated: 2026/08/13 13:41:20 by nmokashi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	apply_disorder(t_stack *stacks, t_flag *flag, double disorder)
{
	if (disorder < 20)
		minmax(stacks, flag);
	else if (disorder < 50)
		medium_sort(stacks, flag);
	else
		radix_sort(stacks, flag);
}

void	adaptive_sort(t_stack *stacks, t_flag *flag)
{
	double	disorder;

	if (is_sorted(stacks->a, stacks->size_a))
		return ;
	disorder = measure_disorder(stacks->a, stacks->size_a);
	stacks->bench.disorder = disorder;
	if (stacks->size_a <= 5 && flag->algo_mode == MODE_ADAPTIVE)
		minmax(stacks, flag);
	else
	{
		if (flag->algo_mode == MODE_SIMPLE)
			minmax(stacks, flag);
		else if (flag->algo_mode == MODE_MEDIUM)
			medium_sort(stacks, flag);
		else if (flag->algo_mode == MODE_COMPLEX)
			radix_sort(stacks, flag);
		else
			apply_disorder(stacks, flag, disorder);
	}
}
