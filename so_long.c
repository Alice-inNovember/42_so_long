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
