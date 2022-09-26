/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:00:02 by junlee2           #+#    #+#             */
/*   Updated: 2022/09/26 10:33:54 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "map_util.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	char	**map;

	if (argc != 2)
		return (0);
	map = map_init(argv[1]);
	if (!map)
	{
		write(1, "map is not valid.\n", 18);
		return (0);
	}
	write(1, "map is valid.\n", 14);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
}
