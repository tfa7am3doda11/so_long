/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-ais <rben-ais@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 07:44:08 by rben-ais          #+#    #+#             */
/*   Updated: 2024/11/21 20:35:23 by rben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int n, char *str, int *count)
{
	if (n < 16)
	{
		ft_putchar(str[n], count);
		return ;
	}
	ft_puthex((n / 16), str, count);
	ft_putchar(str[n % 16], count);
}
