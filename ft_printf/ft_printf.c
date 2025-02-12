/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-ais <rben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:34:50 by rben-ais          #+#    #+#             */
/*   Updated: 2025/02/04 01:14:45 by rben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print(char c, va_list args, int *count)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (c == 'i' || c == 'd')
		ft_putnbr(va_arg(args, int), count);
	else if (c == 'u')
		ft_putu(va_arg(args, unsigned int), count);
	else if (c == 'x')
		ft_puthex(va_arg(args, unsigned int),
			"0123456789abcdef", count);
	else if (c == 'X')
		ft_puthex(va_arg(args, unsigned int),
			"0123456789ABCDEF", count);
	else if (c == 'p')
		ft_putptr((unsigned long)va_arg(args, unsigned long),
			"0123456789abcdef", count);
	else if (c == '%')
		ft_putchar('%', count);
	else
		ft_putchar(c, count);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, s);
	count = 0;
	i = 0;
	if (write(1, 0, 0) == -1)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			if (s[i + 1] != '\0')
			{
				i++;
				ft_print(s[i], args, &count);
			}
		}
		else
			ft_putchar(s[i], &count);
		i++;
	}
	va_end(args);
	return (count);
}
