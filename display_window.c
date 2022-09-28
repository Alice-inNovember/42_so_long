/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
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
	if (r && l && u && d)
		return(so_long.tile_lib.wall_rlud);
	if (r && l && u)
		return(so_long.tile_lib.wall_rlu);
	if (r && l && d)
		return(so_long.tile_lib.wall_rld);
	if (r && u && d)
		return(so_long.tile_lib.wall_rud);
	if (l && u && d)
		return(so_long.tile_lib.wall_lud);
	if (r && l)
		return(so_long.tile_lib.wall_rl);
	if (u && d)
		return(so_long.tile_lib.wall_ud);
	if (r && u)
		return(so_long.tile_lib.wall_ru);
	if (r && d)
		return(so_long.tile_lib.wall_rd);
	if (l && u)
		return(so_long.tile_lib.wall_lu);
	if (l && d)
		return(so_long.tile_lib.wall_ld);
	if (r)
		return(so_long.tile_lib.wall_r);
	if (l)
		return(so_long.tile_lib.wall_l);
	if (u)
		return(so_long.tile_lib.wall_u);
	if (d)
		return(so_long.tile_lib.wall_d);
	return(so_long.tile_lib.wall);
}

void	*wall_select2(t_mlx so_long, int x, int y)
{
	static void	*wall_arr[16];
	int			select;

	if (!wall_arr[0])
	{
		wall_arr[0] = so_long.tile_lib.wall;
		wall_arr[1] = so_long.tile_lib.wall_r;
		wall_arr[2] = so_long.tile_lib.wall_l;
		wall_arr[3] = so_long.tile_lib.wall_rl;
		wall_arr[4] = so_long.tile_lib.wall_u;
		wall_arr[5] = so_long.tile_lib.wall_ru;
		wall_arr[6] = so_long.tile_lib.wall_lu;
		wall_arr[7] = so_long.tile_lib.wall_rlu;
		wall_arr[8] = so_long.tile_lib.wall_d;
		wall_arr[9] = so_long.tile_lib.wall_rd;
		wall_arr[10] = so_long.tile_lib.wall_ld;
		wall_arr[11] = so_long.tile_lib.wall_rld;
		wall_arr[12] = so_long.tile_lib.wall_ud;
		wall_arr[13] = so_long.tile_lib.wall_rud;
		wall_arr[14] = so_long.tile_lib.wall_lud;
		wall_arr[15] = so_long.tile_lib.wall_rlud;
	}
	if(!wall_arr[0])
	{
		write(1, "a", 1);
	}
	select = 0;
	if (x != so_long.x && so_long.map[y][x + 1] == '1')
			select += 1;
	if (x != 0 && so_long.map[y][x - 1] == '1')
			select += 2;
	if (y != 0 && so_long.map[y - 1][x] == '1')
			select += 4;
	if (y != so_long.y && so_long.map[y + 1][x] == '1')
			select += 8;
	return(wall_arr[select]);
}

void	display_cord(t_mlx so_long, int x, int y, int size)
{
	int			(*dp_window)(void *, void *, void*, int, int);
	void        *mlx;
	void        *mlx_win;
	t_tile_lib	*t_lib;
	t_prop_lib	*p_lib;

	dp_window = mlx_put_image_to_window;
	mlx = so_long.mlx;
	mlx_win = so_long.mlx_win;
	t_lib = &(so_long.tile_lib);
	p_lib = &(so_long.prop_lid);
	dp_window(mlx, mlx_win, t_lib->land[0], x * size, y * size);
	if (so_long.map[y][x] == '1')
		dp_window(mlx, mlx_win, wall_select2(so_long, x, y), x * size, y * size);
	else if (so_long.map[y][x] == 'P')
		dp_window(mlx, mlx_win, p_lib->rock, x * size, y * size);
	else if (so_long.map[y][x] == 'C')
		dp_window(mlx, mlx_win, p_lib->coin[0], x * size, y * size);
	else if (so_long.map[y][x] == 'E')
		dp_window(mlx, mlx_win, p_lib->key, x * size, y * size);
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
			display_cord(so_long, x, y, 32);
			x++;
		}
		y++;
	}
}
