/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-ais <rben-ais@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 00:50:31 by rben-ais          #+#    #+#             */
/*   Updated: 2024/11/23 01:11:30 by rben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putu(unsigned int n, int *count)
{
	unsigned long	nb;

	nb = n;
	if (nb < 10)
		ft_putchar(nb + '0', count);
	else
	{
		ft_putu((nb / 10), count);
		ft_putchar(((nb % 10) + '0'), count);
	}
}
