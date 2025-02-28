/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-ais <rben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:59:05 by rben-ais          #+#    #+#             */
/*   Updated: 2025/02/28 01:04:27 by rben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	frame(t_data *data)
{
	data->bat_frame++;
	if (data->bat_frame > 20)
		data->bat_frame = 0;
	return (0);
}

int	update_animations(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'B')
			{
				mlx_put_image_to_window(data->mlx, data->window,
					data->image_floor, i * 32, j * 32);
				if (data->bat_frame <= 10)
					mlx_put_image_to_window(data->mlx, data->window,
						data->image_bat1, i * 32, j * 32);
				else
					mlx_put_image_to_window(data->mlx, data->window,
						data->image_bat2, i * 32, j * 32);
			}
			i++;
		}
		j++;
	}
	return(frame(data));
}
