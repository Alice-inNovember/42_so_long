/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:00:02 by junlee2           #+#    #+#             */
/*   Updated: 2022/10/14 14:36:55 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (keycode == KEY_A)
		x = -1;
	else if (keycode == KEY_D)
		x = 1;
	if (keycode == KEY_W)
		y = -1;
	else if (keycode == KEY_S)
		y = 1;
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	player_control(data, x, y);
	return (0);
}

int	red_button_hook(t_data *data)
{
	exit(EXIT_SUCCESS);
	(void)data;
	return (0);
}

void	player_init(t_data *data)
{
	data->player.coin = 0;
	data->player.face = 'r';
	data->player.key = 0;
}

void	background_init(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			render_background(data, x, y);
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		err_exit("arg is not valid", EINVAL);
	data.mlx = mlx_init();
	map_init(argv[1], &data);
	sprite_init(&data);
	player_init(&data);
	data.mlx_win = mlx_new_window(data.mlx, \
	(data.map.x + 2) * 32, (data.map.y + 2) * 32, "So_long");
	background_init(&data);
	mlx_string_put(data.mlx, data.mlx_win, 16, 16, 0x00FFFF00, "Score : ");
	mlx_key_hook(data.mlx_win, key_hook, &data);
	mlx_hook(data.mlx_win, ON_DESTROY, 0, red_button_hook, &data);
	mlx_loop_hook(data.mlx, render_window, &data);
	mlx_loop(data.mlx);
}
