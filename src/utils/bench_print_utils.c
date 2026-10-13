/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   bench_print_utils.c                               :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: nmokashi <nmokashi@student.42.berlin.de>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/11 15:58:55 by nmokashi         #+#    #+#              */
/*   Updated: 2026/08/11 15:58:55 by nmokashi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_str_fd(int fd, const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(fd, str, len);
}

void	print_nbr_fd(int fd, int n)
{
	char	c;

	if (n >= 10)
		print_nbr_fd(fd, n / 10);
	c = '0' + (n % 10);
	write(fd, &c, 1);
}

void	print_float2_fd(int fd, double n)
{
	int		whole;
	int		decimal;
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	whole = (int) n;
	decimal = (int)((n - whole) * 100 + 0.5);
	print_nbr_fd(fd, whole);
	write(fd, ".", 1);
	c = '0' + (decimal / 10);
	write(fd, &c, 1);
	c = '0' + (decimal % 10);
	write(fd, &c, 1);
}
