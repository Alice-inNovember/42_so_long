/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_display_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:38:42 by junlee2           #+#    #+#             */
/*   Updated: 2022/10/18 15:23:37 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	render_tileset_player(t_data *data, int x, int y, size_t selecter)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
	data->wall.land[0], (x + 1) * 32, (y + 1) * 32);
	if (data->map.map[y][x] == 'P')
	{
		if (data->player.face == 1)
			mlx_put_image_to_window(data->mlx, data->mlx_win, \
			data->player.img_r[selecter], (x + 1) * 32, (y + 1) * 32);
		else
			mlx_put_image_to_window(data->mlx, data->mlx_win, \
			data->player.img_l[selecter], (x + 1) * 32, (y + 1) * 32);
	}
}

void	render_tileset(t_data *data, int x, int y, size_t selecter)
{
	if (data->player.game_status)
		return ;
	render_tileset_player(data, x, y, selecter);
	if (data->map.map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
		data->prop.coin[selecter], (x + 1) * 32, (y + 1) * 32);
	else if (data->map.map[y][x] == 'M')
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
		data->prop.mob[selecter], (x + 1) * 32, (y + 1) * 32);
	else if (data->map.map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
		data->prop.key, (x + 1) * 32, (y + 1) * 32);
	else if (data->map.map[y][x] == 'B')
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
		data->prop.berral, (x + 1) * 32, (y + 1) * 32);
}

void	render_background(t_data *data, int x, int y)
{
	void	*img;

	img = data->wall.land[0];
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
	img, (x + 1) * 32, (y + 1) * 32);
	if (data->map.map[y][x] == '1')
		img = wall_select(data, x, y);
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
	img, (x + 1) * 32, (y + 1) * 32);
}

int	render_window(t_data *data)
{
	int				x;
	int				y;
	static size_t	frame = 0;
	static size_t	tick = 0;

	mob_control(data, tick);
	if (tick % 600 == 0)
	{
		y = 0;
		while (data->map.map[y])
		{
			x = 0;
			while (data->map.map[y][x])
			{
				if (data->map.map[y][x] != '1')
					render_tileset(data, x, y, frame % 8);
				x++;
			}
			y++;
		}
		frame++;
	}
	tick++;
	return (0);
}
