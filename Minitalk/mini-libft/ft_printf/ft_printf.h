/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:06:11 by spiacent          #+#    #+#             */
/*   Updated: 2023/04/20 08:58:05 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		len_pt(unsigned long long nb);
void	ft_put_ptr(unsigned long long nb);
int		ft_putptr(unsigned long long nb);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_conversion(va_list vl, const char format);
int		ft_printf(const char *format, ...);
int		ft_putnbr(int n);
int		ft_puthex(unsigned int nb, char *format, int base);

#endif