/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: nmokashi <nmokashi@student.42.berlin.de>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/11 19:33:26 by nmokashi         #+#    #+#              */
/*   Updated: 2026/08/11 14:41:24 by nmokashi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *stack, t_flag *flag)
{
	int	i;

	if (stack->size_a == 0)
		return ;
	i = stack->size_b;
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = stack->a[0];
	i = 0;
	while (i < stack->size_a - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->size_a--;
	stack->size_b++;
	stack->bench.pb++;
	if (flag->print_op)
		ft_printf("pb\n");
}

void	pa(t_stack *stack, t_flag *flag)
{
	int	i;

	if (stack->size_b == 0)
		return ;
	i = stack->size_a;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = stack->b[0];
	i = 0;
	while (i < stack->size_b - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->size_b--;
	stack->size_a++;
	stack->bench.pa++;
	if (flag->print_op)
		ft_printf("pa\n");
}
