/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_putstr.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: nmokashi <nmokashi@student.42.berlin.de>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/09 17:38:34 by nmokashi         #+#    #+#              */
/*   Updated: 2026/06/09 17:38:37 by nmokashi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_putstr(char *s)
{
	int	count;

	if (!s)
		s = "(null)";
	count = ft_strlen(s);
	write(1, s, count);
	return (count);
}
