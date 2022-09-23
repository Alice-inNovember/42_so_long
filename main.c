/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:00:02 by junlee2           #+#    #+#             */
/*   Updated: 2022/09/23 11:22:32 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <fcntl.h>
#include "get_next_line.h"
#include "mlx.h"

int	main(void)
{
	void	*mlx;
	void	*win;
	int		mapfd;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "test");
	fd = open("maptest.ber", O_RDONLY);
	mlx_loop(mlx);
}
