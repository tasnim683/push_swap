/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_putnbr.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: nmokashi <nmokashi@student.42.berlin.de>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/09 17:39:16 by nmokashi         #+#    #+#              */
/*   Updated: 2026/06/09 17:39:17 by nmokashi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_putnbr(nb / 10);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}
