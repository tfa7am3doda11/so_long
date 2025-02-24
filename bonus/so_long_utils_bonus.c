/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-ais <rben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:03:37 by rben-ais          #+#    #+#             */
/*   Updated: 2025/02/24 19:57:53 by rben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_corners(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			if (!(data->map[0][i] == '1') || !(data->map[data->lines_len
					- 1][i] == '1') || !(data->map[j][0] == '1')
				|| !(data->map[j][data->width_len - 1] == '1'))
			{
				ft_printf("Map corners machi homa hadok\n");
				exit(1);
			}
			i++;
		}
		i = 0;
		j++;
	}
}

void	ber_check(char *str, char *format)
{
	int	i;
	int	len;

	i = ft_strlen(str) - 1;
	len = ft_strlen(format) - 1;
	while (len > 0)
	{
		if (str[i] == format[len] && str[i - 1] == format[len - 1])
		{
			len--;
			i--;
		}
		else
			break ;
	}
	if (len != 0)
	{
		ft_printf("wrong file format!\nError\n");
		exit(1);
	}
}

void	free_things(char **visited, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->lines_len)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

void	digit_check(t_data *data, int j, int i)
{
	if (data->map[j][i] != 'P' && data->map[j][i] != 'E'
		&& data->map[j][i] != 'C' && data->map[j][i] != '0'
		&& data->map[j][i] != '1' && data->map[j][i] != 'B')
		exit(ft_printf("Error\nCheck Input!\n") * 0);
	else if (data->map[j][i] == 'P')
	{
		data->p_count++;
		data->p_y = j;
		data->p_x = i;
	}
	else if (data->map[j][i] == 'E')
	{
		data->e_count++;
		data->e_y = j;
		data->e_x = i;
	}
	else if (data->map[j][i] == 'C')
		data->c_count++;
	else if (data->map[j][i] == 'B')
	{
		data->b_x = i;
		data->b_y = j;
	}
}

int	close_window(t_data *data)
{
	(void) data;
	exit (0);
	return (0);
}
