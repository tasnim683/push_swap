/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_putnbrunsigned.c                               :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: nmokashi <nmokashi@student.42.berlin.de>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/12 17:59:28 by nmokashi         #+#    #+#              */
/*   Updated: 2026/06/12 17:59:28 by nmokashi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrunsigned(unsigned int n)
{
	unsigned int	nb;
	int				count;

	nb = n;
	count = 0;
	if (nb >= 10)
		count += ft_putnbrunsigned(nb / 10);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}
