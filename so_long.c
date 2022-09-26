/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:00:02 by junlee2           #+#    #+#             */
/*   Updated: 2022/09/26 13:37:24 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_cord(t_mlx so_long, int c, int x, int y)
{
	int				(*dp_window)(void *, void *, void*, int, int);
	t_sprite_lib	*s_lib;

	dp_window = mlx_put_image_to_window;
	s_lib = &so_long.sprite_lib;
	if (c == '0')
		dp_window(so_long.mlx, so_long.mlx_win, s_lib->floor_01, x, y);
	else if (c == '1')
		dp_window(so_long.mlx, so_long.mlx_win, s_lib->wall_01, x, y);
	else if (c == 'E')
		dp_window(so_long.mlx, so_long.mlx_win, s_lib->nextlevel, x, y);
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
			display_cord(so_long, so_long.map[y][x], x * 16, y * 16);
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_mlx	so_long;

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
	so_long.mlx = mlx_init();
	sprite_init(so_long.mlx, &so_long.sprite_lib);
	so_long.mlx_win = mlx_new_window(so_long.mlx, 1920, 1080, "Hello world!");
	display_window(so_long);
	mlx_loop(so_long.mlx);
}
