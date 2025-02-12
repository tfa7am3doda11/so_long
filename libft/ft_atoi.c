/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-ais <rben-ais@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:32:19 by rben-ais          #+#    #+#             */
/*   Updated: 2024/11/14 22:54:21 by rben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	space_signe(const char *str, int *i, int *signe)
{
	while (str[*i] && (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13)))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*signe = -1;
		(*i)++;
	}
	return (*i);
}

int	ft_atoi(const char *str)
{
	long long	result;
	int			signe;
	int			i;

	i = 0;
	signe = 1;
	result = 0;
	space_signe(str, &i, &signe);
	while ((str[i]) && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		if (result > 9223372036854775807)
		{
			if (signe > 0)
				return (-1);
			return (0);
		}
		i++;
	}
	return ((int)result * signe);
}
