/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:00:02 by junlee2           #+#    #+#             */
/*   Updated: 2022/10/13 14:07:24 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	player_control(keycode, data);
	ft_putstr_fd("keycode : ", 1);
	ft_putnbr_fd(keycode, 1);
	ft_putstr_fd("\n", 1);
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

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		err_exit("arg is not valid", EINVAL);
	data.mlx = mlx_init();
	map_init(argv[1], &data);
	sprite_init(&data);
	player_init(&data);
	data.mlx_win = \
	mlx_new_window(data.mlx, data.map.x * 32, data.map.y * 32, "So_long");
	mlx_key_hook(data.mlx_win, key_hook, &data);
	mlx_hook(data.mlx_win, ON_DESTROY, 0, red_button_hook, &data);
	mlx_loop_hook(data.mlx, render_window, &data);
	mlx_loop(data.mlx);
}
