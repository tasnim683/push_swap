/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rotate_b.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: nmokashi <nmokashi@student.42.berlin.de>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/01 16:56:19 by nmokashi         #+#    #+#              */
/*   Updated: 2026/08/10 09:59:50 by nmokashi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack *stack, t_flag *flag, int print)
{
	int	first;
	int	i;

	if (stack->size_b <= 1)
		return ;
	i = 0;
	first = stack->b[0];
	while (i < stack->size_b - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[stack->size_b - 1] = first;
	if (print)
		stack->bench.rb++;
	if (print && flag->print_op)
		ft_printf("rb\n");
}

void	rrb(t_stack *stack, t_flag *flag, int print)
{
	int	last;
	int	i;

	if (stack->size_b <= 1)
		return ;
	i = stack->size_b - 1;
	last = stack->b[stack->size_b - 1];
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = last;
	if (print)
		stack->bench.rrb++;
	if (print && flag->print_op)
		ft_printf("rrb\n");
}

void	rrr(t_stack *stack, t_flag *flag)
{
	if (stack->size_a > 1 || stack->size_b > 1)
	{
		rra(stack, flag, 0);
		rrb(stack, flag, 0);
		stack->bench.rrr++;
		if (flag->print_op)
			ft_printf("rrr\n");
	}
}
