/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 08:57:55 by mivendit          #+#    #+#             */
/*   Updated: 2023/04/20 08:57:56 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_ptr(unsigned long long nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

void	ft_put_ptr(unsigned long long nb)
{
	if (nb >= 16)
	{
		ft_put_ptr(nb / 16);
		ft_put_ptr(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar((nb + '0'));
		else
			ft_putchar((nb - 10 + 'a'));
	}
}

int	ft_putptr(unsigned long long ptr)
{
	int	char_printed;

	char_printed = 0;
	char_printed += write(1, "0x", 2);
	if (ptr == 0)
		char_printed += write(1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		char_printed += len_ptr(ptr);
	}
	return (char_printed);
}

int	ft_putnbr(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
	{
		len += ft_putstr("-2");
		nb = 147483648;
	}
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
		len += ft_putnbr(nb / 10);
	len += ft_putchar(nb % 10 + 48);
	return (len);
}

int	ft_puthex(unsigned int nb, char *format, int base)
{
	int	len;

	len = 0;
	if (nb >= (unsigned int)base)
		len += ft_puthex(nb / base, format, base);
	len += ft_putchar(format[nb % base]);
	return (len);
}
