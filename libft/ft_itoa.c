/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-ais <rben-ais@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:45:44 by rben-ais          #+#    #+#             */
/*   Updated: 2024/11/14 00:46:12 by rben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*modriga(char *str, long num, int digit_count)
{
	int		nega;

	nega = 0;
	if (num < 0)
	{
		nega = 1;
		num = -num;
	}
	while (digit_count >= nega)
	{
		str[digit_count] = '0' + (num % 10);
		num /= 10;
		digit_count--;
	}
	if (nega)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digit_count;
	long	num;

	num = n;
	digit_count = ft_count(num);
	str = (char *)malloc((digit_count + 1));
	if (!str)
		return (NULL);
	str[digit_count] = '\0';
	return (modriga(str, num, digit_count - 1));
}
