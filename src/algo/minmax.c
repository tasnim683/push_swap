/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   minmax.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: nmokashi <nmokashi@student.42.berlin.de>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/02 18:43:28 by nmokashi         #+#    #+#              */
/*   Updated: 2026/08/11 14:38:25 by nmokashi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_position(int *arr, int size)
{
	int	i;
	int	min;
	int	pos;

	i = 0;
	min = arr[0];
	pos = 0;
	while (i < size)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

static void	sort_three(t_stack *stack, t_flag *flag)
{
	if (stack->a[0] > stack->a[1]
		&& stack->a[1] < stack->a[2]
		&& stack->a[0] < stack->a[2])
		sa(stack, flag, 1);
	else if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2])
	{
		sa(stack, flag, 1);
		rra(stack, flag, 1);
	}
	else if (stack->a[0] > stack->a[1]
		&& stack->a[1] < stack->a[2]
		&& stack->a[0] > stack->a[2])
		ra(stack, flag, 1);
	else if (stack->a[0] < stack->a[1]
		&& stack->a[1] > stack->a[2]
		&& stack->a[0] < stack->a[2])
	{
		sa(stack, flag, 1);
		ra(stack, flag, 1);
	}
	else if (stack->a[0] < stack->a[1]
		&& stack->a[1] > stack->a[2]
		&& stack->a[0] > stack->a[2])
		rra(stack, flag, 1);
}

void	minmax(t_stack *stack, t_flag *flag)
{
	int	position;

	while (stack->size_a > 3)
	{
		position = find_min_position(stack->a, stack->size_a);
		if (position <= stack->size_a / 2)
		{
			while (position--)
				ra(stack, flag, 1);
		}
		else
		{
			position = stack->size_a - position;
			while (position--)
				rra(stack, flag, 1);
		}
		pb(stack, flag);
	}
	sort_three(stack, flag);
	while (stack->size_b > 0)
		pa(stack, flag);
}
