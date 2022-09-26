/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:40:25 by junlee2           #+#    #+#             */
/*   Updated: 2022/09/26 15:03:32 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"

void	sprite_init(void *mlx, t_sprite_lib *sprite_lib)
{
	int			x;
	int			y;

	sprite_lib->floor_01 = mlx_png_file_to_image(mlx, FLOOR_01, &x, &y);
	sprite_lib->nextlevel = mlx_png_file_to_image(mlx, NEXTLEVEL, &x, &y);
	sprite_lib->wall_01 = mlx_png_file_to_image(mlx, WALL_01, &x, &y);
}
	// sprite_lib->floor_02 = mlx_xpm_file_to_image(mlx, FLOOR_02, &x, &y);
	// sprite_lib->floor_03 = mlx_xpm_file_to_image(mlx, FLOOR_03, &x, &y);
	// sprite_lib->floor_04 = mlx_xpm_file_to_image(mlx, FLOOR_04, &x, &y);
	// sprite_lib->floor_05 = mlx_xpm_file_to_image(mlx, FLOOR_05, &x, &y);
