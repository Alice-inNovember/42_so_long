/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:00:02 by junlee2           #+#    #+#             */
/*   Updated: 2022/10/12 16:22:14 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		err_exit("arg is not valid", EINVAL);
	data.mlx = mlx_init();
	map_init(argv[1], &data);
	sprite_init(&data);
	data.mlx_win = mlx_new_window(data.mlx, data.map.x * 32, data.map.y * 32, "So_long");
	//mlx_loop_hook(data.mlx, 0, &data);
	//mlx_key_hook(data.mlx_win, 0, &data);
	mlx_loop(data.mlx);
}
