/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:00:28 by spiacent          #+#    #+#             */
/*   Updated: 2023/04/20 08:58:00 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_conversion(va_list vl, const char format)
{
	int	l;

	l = 0;
	if (format == 'c')
		l += ft_putchar(va_arg(vl, int));
	else if (format == 's')
		l += ft_putstr(va_arg(vl, char *));
	else if (format == 'p')
		l += ft_putptr(va_arg(vl, unsigned long long));
	else if (format == 'd')
		l += ft_putnbr(va_arg(vl, int));
	else if (format == 'i')
		l += ft_putnbr(va_arg(vl, int));
	else if (format == 'u')
		l += ft_puthex(va_arg(vl, unsigned int), "0123456789", 10);
	else if (format == 'x')
		l += ft_puthex(va_arg(vl, unsigned int), "0123456789abcdef", 16);
	else if (format == 'X')
		l += ft_puthex(va_arg(vl, unsigned int), "0123456789ABCDEF", 16);
	else if (format == '%')
		l += ft_putchar('%');
	return (l);
}

int	ft_printf(const char *format, ...)
{
	int			i;
	va_list		vl;
	int			char_printed;

	i = 0;
	char_printed = 0;
	va_start(vl, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			char_printed += ft_conversion(vl, format[i + 1]);
			i++;
		}
		else
			char_printed += ft_putchar(format[i]);
		i++;
	}
	va_end(vl);
	return (char_printed);
}
