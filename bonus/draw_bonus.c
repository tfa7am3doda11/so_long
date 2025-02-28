/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-ais <rben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:02:55 by rben-ais          #+#    #+#             */
/*   Updated: 2025/02/25 20:42:25 by rben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_pressed(int pressed, t_data *data)
{
	if (pressed == SPACE)
		data->space_held = 1;
	if (pressed == LEFT)
		mv_left(data);
	else if (pressed == RIGHT)
		mv_right(data);
	else if (pressed == UP)
		mv_up(data);
	else if (pressed == DOWN)
		mv_down(data);
	else if (pressed == ESC || pressed == CLOSE_W)
		exit(1);
	else
		write(1, "Invalid Key Pressed!!\n", 23);
	return (0);
}

void	init(t_data *data)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, data->width_len * 32,
			data->lines_len * 32, "TOMB OF THE MASK");
	init_image(data);
	draw_map(data);
	mlx_key_hook(data->window, key_pressed, data);
	mlx_hook(data->window, 17, 0, close_window, data);
	mlx_loop_hook(data->mlx, update_animations, data);
	mlx_loop(data->mlx);
}

void	init_image(t_data *data)
{
	data->floor = "./textures/floor.xpm";
	data->player = "./textures/player.xpm";
	data->door = "./textures/Exit.xpm";
	data->wall = "./textures/wall.xpm";
	data->bat1 = "./textures/bat1_32.xpm";
	data->bat2 = "./textures/bat2_32.xpm";
	data->collectible = "./textures/collectible.xpm";
	ft_xpm(data);
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			draw_map2(data, j, i);
			i++;
		}
		i = 0;
		j++;
	}
}

void	player_on_door(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->window, data->image_door, data->e_x
		* 32, (data->e_y) * 32);
	mlx_put_image_to_window(data->mlx, data->window, data->image_player,
		data->e_x * 32, (data->e_y) * 32);
}
