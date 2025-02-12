/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-ais <rben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:31:39 by rben-ais          #+#    #+#             */
/*   Updated: 2025/02/10 17:31:33 by rben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>

enum
{
	LEFT = 123,
	RIGHT = 124,
	UP = 126,
	DOWN = 125,
	ESC = 53,
	SPACE = 49,
	CLOSE_W = 17,
};

typedef struct s_map
{
	char	**map;
	int		lines_len;
	int		width_len;
	int		p_count;
	int		c_count;
	int		e_count;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		prize;
	int		space_held;

	int		steps;
	void	*mlx;
	void	*window;
	int		image_height;
	int		image_width;

	char	*floor;
	char	*player;
	char	*collectible;
	char	*door;
	char	*wall;
	void	*image_floor;
	void	*image_wall;
	void	*image_door;
	void	*image_player;
	void	*image_collectible;

}			t_data;

int			safe(int x, int y, t_data *data, char **visited);
void		create_lines(char **big_line, char **line, int fd);
void		free_things(char **visited, t_data *data);
void		digit_check(t_data *data, int j, int i);
void		image_move(t_data *data, int x, int y);
void		ber_check(char *str, char *format);
void		draw_map2(t_data *data, int j, int i);
void		player_on_door(t_data *data);
void		check_corners(t_data *data);
int			close_window(t_data *data);
void		init_image(t_data *data);
void		draw_map(t_data *data);
void		mv_right(t_data *data);
void		mv_left(t_data *data);
void		mv_down(t_data *data);
void		width_checker(t_data *data);
void		mv_up(t_data *data);
int			path(t_data *data);
void		init(t_data *data);

#endif