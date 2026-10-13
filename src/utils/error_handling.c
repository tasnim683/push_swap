/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasnimo <tasnimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:06:37 by tasnimo           #+#    #+#             */
/*   Updated: 2026/08/06 21:47:23 by tasnimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static void	check_overflow(const char *str)
{
	long	nb;
	int		sign;
	int		i;

	nb = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		nb = nb * 10 + (str[i] - '0');
		if (nb * sign > 2147483647 || nb * sign < -2147483648)
			error_exit();
		i++;
	}
}

void	validate_args(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!is_valid_number(argv[i]))
			error_exit();
		check_overflow(argv[i]);
		i++;
	}
}
