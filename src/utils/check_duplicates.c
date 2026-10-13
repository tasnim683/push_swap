/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   check_duplicates.c                                :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: nmokashi <nmokashi@student.42.berlin.de>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/04 14:28:10 by nmokashi         #+#    #+#              */
/*   Updated: 2026/08/14 09:41:17 by nmokashi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicates(int *a, int size_a)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_a)
	{
		j = i + 1;
		while (j < size_a)
		{
			if (a[i] == a[j])
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
