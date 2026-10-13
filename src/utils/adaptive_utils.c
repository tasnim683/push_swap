/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   adaptive_utils.c                                  :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: nmokashi <nmokashi@student.42.berlin.de>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/06 17:26:37 by nmokashi         #+#    #+#              */
/*   Updated: 2026/08/11 14:41:10 by nmokashi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_inversions(int *a, int size)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (a[i] > a[j])
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static int	get_max_inversions(int size)
{
	int	max_inversions;

	max_inversions = (size * (size - 1)) / 2;
	return (max_inversions);
}

double	measure_disorder(int *a, int size)
{
	int	inversions;
	int	max_inversions;

	inversions = count_inversions(a, size);
	max_inversions = get_max_inversions(size);
	if (max_inversions == 0)
		return (0.0);
	return ((double) inversions / max_inversions * 100);
}
