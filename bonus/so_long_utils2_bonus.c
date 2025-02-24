/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-ais <rben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:03:46 by rben-ais          #+#    #+#             */
/*   Updated: 2025/02/24 19:59:16 by rben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	width_checker(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (data->width_len != (int)ft_strlen(data->map[i]))
		{
			ft_printf("Map Width mkherbe9\n");
			exit(1);
		}
		i++;
	}
}

void	create_lines(char **big_line, char **line, int fd)
{
	*big_line = ft_calloc(5, 1);
	*line = get_next_line(fd);
	if (!*line)
	{
		ft_printf("Error\nempty file!\n");
		exit(1);
	}
}

void	image_move(t_data *data, int x, int y)
{
	if(data->p_x + x == data->b_x && data->p_y + y == data->b_y)
	{
		printf("\033[1;31mGAME OVER\033[0m\n");
		exit(1);
	}
	mlx_put_image_to_window(data->mlx, data->window, data->image_floor,
		(data->p_x + x) * 32, (data->p_y + y) * 32);
	mlx_put_image_to_window(data->mlx, data->window, data->image_player,
		(data->p_x + x) * 32, (data->p_y + y) * 32);
	mlx_put_image_to_window(data->mlx, data->window, data->image_floor,
		(data->p_x) * 32, (data->p_y) * 32);
	mlx_put_image_to_window(data->mlx, data->window, data->image_door,
		data->e_x * 32, data->e_y * 32);
}
