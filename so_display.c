/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:38:42 by junlee2           #+#    #+#             */
/*   Updated: 2022/10/17 12:59:50 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*wall_select(t_data *data, int x, int y)
{
	int			select;

	select = 0;
	if (x != data->map.x - 1 && data->map.map[y][x + 1] == '1')
			select += 1;
	if (x != 0 && data->map.map[y][x - 1] == '1')
			select += 2;
	if (y != 0 && data->map.map[y - 1][x] == '1')
			select += 4;
	if (y != data->map.y - 1 && data->map.map[y + 1][x] == '1')
			select += 8;
	return (data->wall.wall[select]);
}

void	render_tileset(t_data *data, int x, int y, size_t frame)
{
	void	*img;
	int		x_cord;
	int		y_cord;

	x_cord = (x + 1) * 32;
	y_cord = (y + 1) * 32;
	img = data->wall.land[0];
	if (data->map.map[y][x] == '1')
		return ;
	else if (data->map.map[y][x] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, img, x_cord, y_cord);
		if (data->player.face == 1)
			img = data->player.img_r[frame % 8];
		else
			img = data->player.img_l[frame % 8];
	}
	else if (data->map.map[y][x] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, img, x_cord, y_cord);
		img = data->prop.coin[frame % 8];
	}
	else if (data->map.map[y][x] == 'M')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, img, x_cord, y_cord);
		img = data->prop.mob[frame % 8];
	}
	else if (data->map.map[y][x] == 'E')
		img = data->prop.key;
	else if (data->map.map[y][x] == 'B')
		img = data->prop.berral;
	else
		img = data->wall.land[0];
	mlx_put_image_to_window(data->mlx, data->mlx_win, img, x_cord, y_cord);
}

void	render_background(t_data *data, int x, int y)
{
	void	*img;
	int		x_cord;
	int		y_cord;

	x_cord = (x + 1) * 32;
	y_cord = (y + 1) * 32;
	img = data->wall.land[0];
	mlx_put_image_to_window(data->mlx, data->mlx_win, img, x_cord, y_cord);
	if (data->map.map[y][x] == '1')
		img = wall_select(data, x, y);
	mlx_put_image_to_window(data->mlx, data->mlx_win, img, x_cord, y_cord);
}

int	render_window(t_data *data)
{
	int				x;
	int				y;
	static size_t	frame;
	static size_t	tick;

	y = 0;
	if (tick % 500 == 0)
	{
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
		mlx_sync(MLX_SYNC_WIN_FLUSH_CMD, data->mlx_win);
		frame++;
	}
	tick++;
	return (0);
}
