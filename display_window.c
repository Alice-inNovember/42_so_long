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

void	wall_init(t_mlx *so_long, void	**wall_arr)
{
	wall_arr[0] = so_long->tile_lib.wall;
	wall_arr[1] = so_long->tile_lib.wall_r;
	wall_arr[2] = so_long->tile_lib.wall_l;
	wall_arr[3] = so_long->tile_lib.wall_rl;
	wall_arr[4] = so_long->tile_lib.wall_u;
	wall_arr[5] = so_long->tile_lib.wall_ru;
	wall_arr[6] = so_long->tile_lib.wall_lu;
	wall_arr[7] = so_long->tile_lib.wall_rlu;
	wall_arr[8] = so_long->tile_lib.wall_d;
	wall_arr[9] = so_long->tile_lib.wall_rd;
	wall_arr[10] = so_long->tile_lib.wall_ld;
	wall_arr[11] = so_long->tile_lib.wall_rld;
	wall_arr[12] = so_long->tile_lib.wall_ud;
	wall_arr[13] = so_long->tile_lib.wall_rud;
	wall_arr[14] = so_long->tile_lib.wall_lud;
	wall_arr[15] = so_long->tile_lib.wall_rlud;
}

void	*wall_select(t_mlx *so_long, int x, int y)
{
	static void	*wall_arr[16];
	int			select;

	if (!wall_arr[0])
		wall_init(so_long, wall_arr);
	select = 0;
	if (x != so_long->x && so_long->map[y][x + 1] == '1')
			select += 1;
	if (x != 0 && so_long->map[y][x - 1] == '1')
			select += 2;
	if (y != 0 && so_long->map[y - 1][x] == '1')
			select += 4;
	if (y != so_long->y && so_long->map[y + 1][x] == '1')
			select += 8;
	return (wall_arr[select]);
}

void	display_cord(t_mlx *so_long, int x, int y, size_t cnt)
{
	int			(*dp_window)(void *, void *, void*, int, int);
	void		*mlx_win;
	void		*img;

	dp_window = mlx_put_image_to_window;
	mlx_win = so_long->mlx_win;
	img = so_long->tile_lib.land[cnt % 2];
	dp_window(so_long->mlx, mlx_win, img, x * 32, y * 32);
	if (so_long->map[y][x] == '1')
		img = wall_select(so_long, x, y);
	else if (so_long->map[y][x] == 'P')
		img = so_long->prop_lib.rock;
	else if (so_long->map[y][x] == 'C')
		img = so_long->prop_lib.coin[cnt % 8];
	else if (so_long->map[y][x] == 'E')
		img = so_long->prop_lib.key;
	dp_window(so_long->mlx, mlx_win, img, x * 32, y * 32);
}

int	display_window(t_mlx *so_long)
{
	int				x;
	int				y;
	static size_t	i;
	static size_t	cnt;

	if (i % 5 == 0)
	{
		y = 0;
		while (so_long->map[y])
		{
			x = 0;
			while (so_long->map[y][x])
			{
				display_cord(so_long, x, y, cnt);
				x++;
			}
			y++;
		}
		mlx_sync(MLX_SYNC_WIN_FLUSH_CMD, so_long->mlx_win);
		mlx_sync(MLX_SYNC_WIN_CMD_COMPLETED, so_long->mlx_win);
		cnt++;
	}
	i++;
	return (0);
}
