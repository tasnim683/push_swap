/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   radix.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: nmokashi <nmokashi@student.42.berlin.de>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/04 14:35:13 by nmokashi         #+#    #+#              */
/*   Updated: 2026/08/09 13:02:10 by nmokashi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack *stack)
{
	int	i;
	int	max;
	int	bits;

	i = 0;
	max = stack->a[0];
	while (i < stack->size_a)
	{
		if (stack->a[i] > max)
			max = stack->a[i];
		i++;
	}
	bits = 0;
	while (max)
	{
		bits++;
		max >>= 1;
	}
	return (bits);
}

void	radix_sort(t_stack *stack, t_flag *flag)
{
	int	max_bits;
	int	bit;
	int	i;
	int	count;

	count = stack->size_a;
	map_values(stack->a, stack->size_a);
	max_bits = get_max_bits(stack);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < count)
		{
			if (((stack->a[0] >> bit) & 1) == 0)
				pb(stack, flag);
			else
				ra(stack, flag, 1);
			i++;
		}
		while (stack->size_b > 0)
			pa(stack, flag);
		bit++;
	}
}
