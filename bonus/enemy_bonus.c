/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-ais <rben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:26:37 by rben-ais          #+#    #+#             */
/*   Updated: 2025/02/12 17:40:58 by rben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	mv_bat(t_data *data)
{
	int	flag;
	
	flag = 1;
    while(data->map[data->B_y][data->B_x] != 'P' && data->map[data->B_y][data->B_x] != '1')
	{
    	if (data->map[data->B_y][data->B_x + 1] != '1' && flag == 1)
			data->B_x++;
    	if (data->map[data->B_y][data->B_x - 1] != '1' && flag == -1)
			data->B_x--;
    	if (data->map[data->B_y][data->B_x - 1] == '1' && flag == -1)
			flag = 1;
    	if (data->map[data->B_y][data->B_x + 1] == '1' && flag == 1)
			flag = -1;
	}
    // Update bat animation frame
    data->bat_frame = (data->bat_frame + 1) % 2; // Toggle between 0 and 1
}

int	check_collision(t_data *data)
{
	if (data->p_x == data->B_x && data->p_y == data->B_y)
		return (1);
	return (0);
}

void	update_bat_position(t_data *data)
{
	mv_bat(data);
	if (check_collision(data))
	{
		ft_printf("Game Over! You touched the bat!\n");
		exit(0);
	}
}