/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-ais <rben-ais@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:27:26 by rben-ais          #+#    #+#             */
/*   Updated: 2024/11/22 21:09:21 by rben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthexp(size_t n, char *str, int *count)
{
	if (n < 16)
	{
		ft_putchar(str[n], count);
		return ;
	}
	ft_puthexp((n / 16), str, count);
	ft_putchar(str[n % 16], count);
}

void	ft_putptr(unsigned long n, char *str, int *count)
{
	ft_putstr("0x", count);
	ft_puthexp(n, str, count);
}
