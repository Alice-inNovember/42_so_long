/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:00:02 by junlee2           #+#    #+#             */
/*   Updated: 2022/10/11 11:21:19 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_mlx *so_long)
{
	t_player	*player;
	int			ax;
	int			ay;

	player = &so_long->player;
	ax = 0;
	ay = 0;
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_W)
		ay = -1;
	if (keycode == KEY_A)
		ax = -1;
	if (keycode == KEY_S)
		ay = 1;
	if (keycode == KEY_D)
		ax = 1;
	so_long->map[player->y][player->x] = '0';
	so_long->map[player->y + ay][player->x + ax] = 'P';
	so_long->player.x += ax;
	so_long->player.y += ay;
	ft_putstr_fd("key_press : ", 0);
	ft_putnbr_fd(keycode, 0);
	write(1, "\n", 1);
	return (0);
}

void	player_init(t_mlx *so_long, int x, int y)
{
	while (so_long->map[y])
	{
		x = 0;
		while (so_long->map[y][x])
		{
			if (so_long->map[y][x] == 'P')
			{
				so_long->player.x = x;
				so_long->player.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_mlx			so_long;
	int				size_x;
	int				size_y;

	if (argc != 2)
		err_exit("arg is not valid", EINVAL);
	so_long.map = map_init(argv[1]);
	if (!so_long.map)
		err_exit("map is not valid", EINVAL);
	map_size(&so_long);
	player_init(&so_long, 0, 0);
	so_long.mlx = mlx_init();
	sprite_init(&so_long);
	size_x = (so_long.x + 1) * 32;
	size_y = (so_long.y + 1) * 32;
	so_long.mlx_win = mlx_new_window(so_long.mlx, size_x, size_y, "So_long");
	mlx_do_sync(so_long.mlx);
	mlx_loop_hook(so_long.mlx, display_window, &so_long);
	mlx_key_hook(so_long.mlx_win, key_hook, &so_long);
	mlx_loop(so_long.mlx);
}
