/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: nmokashi <nmokashi@student.42.berlin.de>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/09 17:42:41 by nmokashi         #+#    #+#              */
/*   Updated: 2026/06/12 18:37:11 by nmokashi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putstr(char *s);
int	ft_putnbrunsigned(unsigned int n);
int	checkptr(unsigned long ptr);
int	ft_putptr(void *ptr);
int	ft_puthex(unsigned long num, char *hex);

int	ft_printf(const char *toprint, ...);

#endif
