/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-ais <rben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:03:16 by rben-ais          #+#    #+#             */
/*   Updated: 2025/02/12 15:44:50 by rben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_checker(t_data *data)
{
	int	i;
	int	j;

	width_checker(data);
	i = 0;
	j = 0;
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			digit_check(data, j, i);
			i++;
		}
		i = 0;
		j++;
	}
	if (data->c_count == 0 || data->p_count != 1 || data->e_count != 1)
	{
		perror("Collectables or player or exit is missing!");
		exit(1);
	}
	check_corners(data);
}

void	data_reader(t_data *data, int fd)
{
	char	*line;
	char	*big_line;

	create_lines(&big_line, &line, fd);
	data->width_len = ft_strlen(line) - 1;
	while (line)
	{
		big_line = ft_strjoin(big_line, line);
		free(line);
		data->lines_len++;
		line = get_next_line(fd);
		if (line)
		{
			if ((int)ft_strlen(line) < data->width_len)
			{
				perror("too much new lines!\n");
				exit(1);
			}
		}
	}
	data->map = ft_split(big_line, '\n');
	free(big_line);
}

int	path(t_data *data)
{
	int		x;
	int		y;
	int		a;
	int		i;
	char	**visited;

	x = data->p_x;
	y = data->p_y;
	a = 0;
	i = 0;
	visited = malloc(data->lines_len * sizeof(char *));
	while (i < data->lines_len)
	{
		visited[i] = malloc(data->width_len * sizeof(char));
		i++;
	}
	a = safe(x, y, data, visited);
	free_things(visited, data);
	return (a);
}

int	safe(int x, int y, t_data *data, char **visited)
{
	if ((data->map[y][x] == '0' || data->map[y][x] == 'C'
			|| data->map[y][x] == 'P' || data->map[y][x] == 'E')
		&& visited[y][x] != 'V')
	{
		visited[y][x] = 'V';
		if (data->map[y][x] == 'E' || data->map[y][x] == 'C')
		{
			data->prize++;
			if (data->prize == data->c_count + 1)
				return (1);
		}
		if (safe(x, y + 1, data, visited) == 1)
			return (1);
		if (safe(x, y - 1, data, visited) == 1)
			return (1);
		if (safe(x + 1, y, data, visited) == 1)
			return (1);
		if (safe(x - 1, y, data, visited) == 1)
			return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
    t_data	*data;
    int		fd;

    data = (t_data *)malloc(sizeof(t_data));
    if (!data)
        exit(0);
    ft_memset(data, 0, sizeof(t_data));
    if (ac != 2)
        exit(ft_printf("Error\nnot enough arguments\n") * 0);
    ber_check(av[1], ".ber");
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
    {
        free(data);
        perror("Error\n");
        exit(1);
    }
    data_reader(data, fd);
    map_checker(data);
    if (path(data) == 0)
    {
        perror("Error\nInvalid Path!\n");
        exit(0);
    }
    init(data);
    while (1)
    {
        update_bat_position(data);
        draw_map(data); // Redraw the map to update bat position and animation
        usleep(100000); // Adjust the sleep time for bat speed
    }
}
