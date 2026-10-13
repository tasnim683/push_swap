/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   algo_medium_utils.c                               :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: nmokashi <nmokashi@student.42.berlin.de>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/03 21:44:10 by nmokashi         #+#    #+#              */
/*   Updated: 2026/08/10 09:59:43 by nmokashi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	copy_array(int *dst, int *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
}

static void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*create_sorted_array(int *a, int size)
{
	int	*sorted;

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return (NULL);
	copy_array(sorted, a, size);
	bubble_sort(sorted, size);
	return (sorted);
}

void	push_max_back(t_stack *stacks, t_flag *flag)
{
	int	pos;

	pos = find_max_position(stacks->b, stacks->size_b);
	if (pos <= stacks->size_b / 2)
	{
		while (pos--)
			rb(stacks, flag, 1);
	}
	else
	{
		pos = stacks->size_b - pos;
		while (pos--)
			rrb(stacks, flag, 1);
	}
	pa(stacks, flag);
}
