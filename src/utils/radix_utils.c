/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   radix_utils.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: nmokashi <nmokashi@student.42.berlin.de>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/10 10:03:07 by nmokashi         #+#    #+#              */
/*   Updated: 2026/08/10 10:03:07 by nmokashi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*copy_array(int *a, int size)
{
	int	*copy;
	int	i;

	copy = malloc(sizeof(int) * size);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = a[i];
		i++;
	}
	return (copy);
}

static void	sort_array(int *a, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (a[j] > a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	find_position(int *a, int size, int find)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (a[i] == find)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

void	map_values(int *a, int size)
{
	int	*sorted;
	int	i;

	sorted = copy_array(a, size);
	if (!sorted)
		return ;
	sort_array(sorted, size);
	i = 0;
	while (i < size)
	{
		a[i] = find_position(sorted, size, a[i]);
		i++;
	}
	free(sorted);
}
