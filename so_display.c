/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:38:42 by junlee2           #+#    #+#             */
/*   Updated: 2022/10/13 12:40:18 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_init(t_data *data, void **wall_arr)
{
	wall_arr[0] = data->wall.wall;
	wall_arr[1] = data->wall.wall_r;
	wall_arr[2] = data->wall.wall_l;
	wall_arr[3] = data->wall.wall_rl;
	wall_arr[4] = data->wall.wall_u;
	wall_arr[5] = data->wall.wall_ru;
	wall_arr[6] = data->wall.wall_lu;
	wall_arr[7] = data->wall.wall_rlu;
	wall_arr[8] = data->wall.wall_d;
	wall_arr[9] = data->wall.wall_rd;
	wall_arr[10] = data->wall.wall_ld;
	wall_arr[11] = data->wall.wall_rld;
	wall_arr[12] = data->wall.wall_ud;
	wall_arr[13] = data->wall.wall_rud;
	wall_arr[14] = data->wall.wall_lud;
	wall_arr[15] = data->wall.wall_rlud;
}

void	*wall_select(t_data *data, int x, int y)
{
	static void	*wall_arr[16];
	int			select;

	if (!wall_arr[0])
		wall_init(data, wall_arr);
	select = 0;
	if (x != data->map.x - 1 && data->map.map[y][x + 1] == '1')
			select += 1;
	if (x != 0 && data->map.map[y][x - 1] == '1')
			select += 2;
	if (y != 0 && data->map.map[y - 1][x] == '1')
			select += 4;
	if (y != data->map.y - 1 && data->map.map[y + 1][x] == '1')
			select += 8;
	return (wall_arr[select]);
}

void	render_tileset(t_data *data, int x, int y, size_t frame)
{
	void	*img;

	if (data->map.map[y][x] == '1')
		img = wall_select(data, x, y);
	else if (data->map.map[y][x] == 'P')
		img = data->player.img_r;
	else if (data->map.map[y][x] == 'C')
		img = data->prop.coin[frame % 8];
	else if (data->map.map[y][x] == 'E')
		img = data->prop.key;
	else
		img = data->wall.land[0];
	mlx_put_image_to_window(data->mlx, data->mlx_win, img, x * 32, y * 32);
}

int	render_window(t_data *data)
{
	int				x;
	int				y;
	static size_t	frame;

	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			render_tileset(data, x, y, frame);
			x++;
		}
		y++;
	}
	frame++;
	return (0);
}
