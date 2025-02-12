/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-ais <rben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:31:02 by rben-ais          #+#    #+#             */
/*   Updated: 2025/02/10 17:31:28 by rben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mv_up(t_data *data)
{
	if (data->map[data->p_y - 1][data->p_x] != '1')
		ft_printf("steps : %d\n", ++data->steps);
	while (data->map[data->p_y - 1][data->p_x] != '1')
	{
		if (data->map[data->p_y - 1][data->p_x] != '1')
		{
			if (data->map[data->p_y - 1][data->p_x] == 'C')
			{
				data->map[data->p_y - 1][data->p_x] = '0';
				data->c_count--;
			}
			image_move(data, 0, -1);
			if (data->map[data->p_y - 1][data->p_x] == 'E')
				player_on_door(data);
			if (data->map[data->p_y - 1][data->p_x] == 'E' 
				&& data->c_count == 0)
				exit(0);
			data->p_y--;
		}
		if (data->space_held)
			break ;
	}
}

void	mv_down(t_data *data)
{
	if (data->map[data->p_y + 1][data->p_x] != '1')
		ft_printf("steps : %d\n", ++data->steps);
	while (data->map[data->p_y + 1][data->p_x] != '1')
	{
		if (data->map[data->p_y + 1][data->p_x] != '1')
		{
			if (data->map[data->p_y + 1][data->p_x] == 'C')
			{
				data->map[data->p_y + 1][data->p_x] = '0';
				data->c_count--;
			}
			image_move(data, 0, 1);
			if (data->map[data->p_y + 1][data->p_x] == 'E')
				player_on_door(data);
			if (data->map[data->p_y + 1][data->p_x] == 'E' 
				&& data->c_count == 0)
				exit(0);
			data->p_y++;
		}
		if (data->space_held)
			break ;
	}
}

void	mv_left(t_data *data)
{
	if (data->map[data->p_y][data->p_x - 1] != '1')
		ft_printf("steps : %d\n", ++data->steps);
	while (data->map[data->p_y][data->p_x - 1] != '1')
	{
		if (data->map[data->p_y][data->p_x - 1] != '1')
		{
			if (data->map[data->p_y][data->p_x - 1] == 'C')
			{
				data->map[data->p_y][data->p_x - 1] = '0';
				data->c_count--;
			}
			image_move(data, -1, 0);
			if (data->map[data->p_y][data->p_x - 1] == 'E')
				player_on_door(data);
			if (data->map[data->p_y][data->p_x - 1] == 'E' 
				&& data->c_count == 0)
				exit(0);
			data->p_x--;
		}
		if (data->space_held)
			break ;
	}
}

void	mv_right(t_data *data)
{
	if (data->map[data->p_y][data->p_x + 1] != '1')
		ft_printf("steps : %d\n", ++data->steps);
	while (data->map[data->p_y][data->p_x + 1] != '1')
	{
		if (data->map[data->p_y][data->p_x + 1] != '1')
		{
			if (data->map[data->p_y][data->p_x + 1] == 'C')
			{
				data->map[data->p_y][data->p_x + 1] = '0';
				data->c_count--;
			}
			image_move(data, 1, 0);
			if (data->map[data->p_y][data->p_x + 1] == 'E')
				player_on_door(data);
			if (data->map[data->p_y][data->p_x + 1] == 'E' 
				&& data->c_count == 0)
				exit(0);
			data->p_x++;
		}
		if (data->space_held)
		{
			data->space_held = 0;
			break ;
		}
	}
}

void	draw_map2(t_data *data, int j, int i)
{
	if (data->map[j][i] == '1')
		mlx_put_image_to_window(data->mlx, data->window, data->image_wall, i
			* 32, j * 32);
	if (data->map[j][i] == '0' || data->map[j][i] == 'P'
		|| data->map[j][i] == 'E' || data->map[j][i] == 'C')
		mlx_put_image_to_window(data->mlx, data->window, data->image_floor, i
			* 32, j * 32);
	if (data->map[j][i] == 'P')
		mlx_put_image_to_window(data->mlx, data->window, data->image_player, i
			* 32, j * 32);
	if (data->map[j][i] == 'E')
		mlx_put_image_to_window(data->mlx, data->window, data->image_door, i
			* 32, j * 32);
	if (data->map[j][i] == 'C')
		mlx_put_image_to_window(data->mlx, data->window,
			data->image_collectible, i * 32, j * 32);
}
