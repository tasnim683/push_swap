/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_puthex.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: nmokashi <nmokashi@student.42.berlin.de>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/12 18:58:15 by nmokashi         #+#    #+#              */
/*   Updated: 2026/06/12 18:58:15 by nmokashi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long num, char *hex)
{
	int		count;

	count = 0;
	if (num >= 16)
	{
		count += ft_puthex(num / 16, hex);
	}
	count += ft_putchar(hex[num % 16]);
	return (count);
}
