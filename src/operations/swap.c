/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   swap.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: nmokashi <nmokashi@student.42.berlin.de>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/11 17:10:22 by nmokashi         #+#    #+#              */
/*   Updated: 2026/08/11 14:40:59 by nmokashi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack, t_flag *flag, int print)
{
	int	temp;

	if (stack->size_a <= 1)
		return ;
	temp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = temp;
	if (print)
		stack->bench.sa++;
	if (print && flag->print_op)
		ft_printf("sa\n");
}

void	sb(t_stack *stack, t_flag *flag, int print)
{
	int	temp;

	if (stack->size_b <= 1)
		return ;
	temp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = temp;
	if (print)
		stack->bench.sb++;
	if (print && flag->print_op)
		ft_printf("sb\n");
}

void	ss(t_stack *stack, t_flag *flag)
{
	sa(stack, flag, 0);
	sb(stack, flag, 0);
	stack->bench.ss++;
	if (flag->print_op)
		ft_printf("ss\n");
}
