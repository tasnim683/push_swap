/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: nmokashi <nmokashi@student.42.berlin.de>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/09 17:29:26 by nmokashi         #+#    #+#              */
/*   Updated: 2026/06/12 19:40:38 by nmokashi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putargs(va_list args, const char c)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == '%')
		return (ft_putchar('%'));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'u')
		return (ft_putnbrunsigned(va_arg(args, unsigned int)));
	if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	if (c == 'x')
		return (ft_puthex(va_arg(args, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	return (0);
}

int	ft_printf(const char *toprint, ...)
{
	va_list	args;
	int		printed;
	int		i;

	printed = 0;
	i = 0;
	va_start(args, toprint);
	while (toprint != NULL && toprint[i] != '\0')
	{
		if (toprint[i] == '%')
		{
			i++;
			printed += ft_putargs(args, toprint[i]);
		}
		else
		{
			printed += ft_putchar(toprint[i]);
		}
		i++;
	}
	va_end(args);
	return (printed);
}
