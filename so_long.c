/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:00:02 by junlee2           #+#    #+#             */
/*   Updated: 2022/09/27 13:37:08 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*wall_select(t_mlx so_long, int x, int y)
{
	int	u;
	int	d;
	int	r;
	int	l;
	
	u = 0;
	d = 0;
	r = 0;
	l = 0;
	if (x != so_long.x && so_long.map[y][x + 1] == '1')
			r = 1;
	if (x != 0 && so_long.map[y][x - 1] == '1')
			l = 1;
	if (y != so_long.y && so_long.map[y + 1][x] == '1')
			d = 1;
	if (y != 0 && so_long.map[y - 1][x] == '1')
			u = 1;
	if (r && l && d && u)
		return(so_long.prop_lid.berral);
	if (r && l && d)
		return(so_long.tile_lib.wall_vd);
	if (r && l && u)
		return(so_long.tile_lib.wall_vu);
	if (u && d && r)
		return(so_long.tile_lib.wall_hr);
	if (u && d && l)
		return(so_long.tile_lib.wall_hl);
	if (r && l)
		return(so_long.tile_lib.wall_v);
	if (u && d)
		return(so_long.tile_lib.wall_h);
	if (u && r)
		return(so_long.tile_lib.wall_dl);
	if (u && l)
		return(so_long.tile_lib.wall_dr);
	if (d && r)
		return(so_long.tile_lib.wall_ul);
	if (d && l)
		return(so_long.tile_lib.wall_ur);
	if (u)
		return(so_long.tile_lib.wall_de);
	if (d)
		return(so_long.tile_lib.wall_ue);
	if (r)
		return(so_long.tile_lib.wall_le);
	if (l)
		return(so_long.tile_lib.wall_re);
	return(so_long.prop_lid.berral);
}

void	display_cord(t_mlx so_long, int c, int x, int y)
{
	int			(*dp_window)(void *, void *, void*, int, int);
	int			s;
	t_tile_lib	*t_lib;
	t_prop_lib	*p_lib;

	dp_window = mlx_put_image_to_window;
	s = 32;
	t_lib = &(so_long.tile_lib);
	p_lib = &(so_long.prop_lid);
	dp_window(so_long.mlx, so_long.mlx_win, t_lib->land[0], x * s, y * s);
	if (c == '1')
		dp_window(so_long.mlx, so_long.mlx_win, wall_select(so_long, x, y), x * s, y * s);
	else if (c == 'P')
		dp_window(so_long.mlx, so_long.mlx_win, p_lib->rock, x * s, y * s);
	else if (c == 'C')
		dp_window(so_long.mlx, so_long.mlx_win, p_lib->coin[0], x * s, y * s);
	else if (c == 'E')
		dp_window(so_long.mlx, so_long.mlx_win, p_lib->key, x * s, y * s);
}

void	display_window(t_mlx so_long)
{
	int	x;
	int	y;

	y = 0;
	while (so_long.map[y])
	{
		x = 0;
		while (so_long.map[y][x])
		{
			display_cord(so_long, so_long.map[y][x], x, y);
			x++;
		}
		y++;
	}
}

void	map_size(t_mlx	*so_long)
{
	so_long->x = 0;
	so_long->y = 0;
	while (so_long->map[so_long->y])
		so_long->y++;
	while (so_long->map[0][so_long->x])
		so_long->x++;
	so_long->x--;
	so_long->y--;
}

int	main(int argc, char **argv)
{
	t_mlx	so_long;
	int		size_x;
	int		size_y;

	if (argc != 2)
	{
		write(1, "arg is not valid.\n", 18);
		return (0);
	}
	so_long.map = map_init(argv[1]);
	if (!so_long.map)
	{
		write(1, "map is not valid.\n", 18);
		return (0);
	}
	map_size(&so_long);
	so_long.mlx = mlx_init();
	sprite_init(&so_long);
	size_x = (so_long.x + 1) * 32;
	size_y = (so_long.y + 1) * 32;
	so_long.mlx_win = mlx_new_window(so_long.mlx, size_x, size_y, "Hello world!");
	display_window(so_long);
	mlx_loop(so_long.mlx);
}
