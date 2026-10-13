/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   medium.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: nmokashi <nmokashi@student.42.berlin.de>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/03 19:12:14 by nmokashi         #+#    #+#              */
/*   Updated: 2026/08/11 15:07:03 by nmokashi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_position(int *arr, int size)
{
	int	i;
	int	max;
	int	pos;

	i = 0;
	max = arr[0];
	pos = 0;
	while (i < size)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int	get_chunk_size(int size)
{
	int	chunk_size;

	chunk_size = 1;
	while (chunk_size + 1 <= size / (chunk_size + 1))
		chunk_size++;
	return (chunk_size);
}

int	get_chunk(int value, int *sorted, int size, int chunk_size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i / chunk_size);
		i++;
	}
	return (-1);
}

void	push_chunk(t_chunk *data, t_flag *flag)
{
	int	size;

	size = data->stack->size_a;
	while (size > 0)
	{
		if (get_chunk(data->stack->a[0], data->sorted, data->size,
				data->chunk_size) == data->chunk)
			pb(data->stack, flag);
		else
			ra(data->stack, flag, 1);
		size--;
	}
}

void	medium_sort(t_stack *stack, t_flag *flag)
{
	t_chunk	data;
	int		chunks;

	data.stack = stack;
	data.sorted = create_sorted_array(stack->a, stack->size_a);
	if (!data.sorted)
		return ;
	data.size = stack->size_a;
	data.chunk_size = get_chunk_size(stack->size_a);
	chunks = (stack->size_a + data.chunk_size - 1) / data.chunk_size;
	data.chunk = chunks - 1;
	while (data.chunk >= 0)
	{
		push_chunk(&data, flag);
		data.chunk--;
	}
	while (stack->size_b > 0)
		push_max_back(stack, flag);
	free(data.sorted);
}
