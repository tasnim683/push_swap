/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_putptr.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: nmokashi <nmokashi@student.42.berlin.de>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/12 17:59:43 by nmokashi         #+#    #+#              */
/*   Updated: 2026/06/12 18:41:27 by nmokashi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		return (ft_putstr("(nil)"));
	}
	count += ft_putstr("0x");
	count += ft_puthex((unsigned long)ptr, "0123456789abcdef");
	return (count);
}
