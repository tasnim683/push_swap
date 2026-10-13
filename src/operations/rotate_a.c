/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rotate_a.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: nmokashi <nmokashi@student.42.berlin.de>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/31 21:32:21 by nmokashi         #+#    #+#              */
/*   Updated: 2026/08/11 14:40:18 by nmokashi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack, t_flag *flag, int print)
{
	int	first;
	int	i;

	if (stack->size_a <= 1)
		return ;
	i = 0;
	first = stack->a[0];
	while (i < stack->size_a - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[stack->size_a - 1] = first;
	if (print)
		stack->bench.ra++;
	if (print && flag->print_op)
		ft_printf("ra\n");
}

void	rra(t_stack *stack, t_flag *flag, int print)
{
	int	last;
	int	i;

	if (stack->size_a <= 1)
		return ;
	i = stack->size_a - 1;
	last = stack->a[stack->size_a - 1];
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = last;
	if (print)
		stack->bench.rra++;
	if (print && flag->print_op)
		ft_printf("rra\n");
}

void	rr(t_stack *stack, t_flag *flag)
{
	if (stack->size_a > 1 || stack->size_b > 1)
	{
		ra(stack, flag, 0);
		rb(stack, flag, 0);
		stack->bench.rr++;
		if (flag->print_op)
			ft_printf("rr\n");
	}
}
