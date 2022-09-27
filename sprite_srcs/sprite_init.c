/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:40:25 by junlee2           #+#    #+#             */
/*   Updated: 2022/09/27 11:41:47 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"

void	tile_init(t_mlx *so_long, int x, int y)
{
	t_tile_lib	*tile;

	tile = &(so_long->tile_lib);
	tile->land[0] = mlx_png_file_to_image(so_long->mlx, LAND_00, &x, &y);
	tile->land[1] = mlx_png_file_to_image(so_long->mlx, LAND_01, &x, &y);
	tile->wall_rlud = mlx_png_file_to_image(so_long->mlx, WALL_RLUD, &x, &y);
	tile->wall_rlu = mlx_png_file_to_image(so_long->mlx, WALL_RLU, &x, &y);
	tile->wall_rld = mlx_png_file_to_image(so_long->mlx, WALL_RLD, &x, &y);
	tile->wall_rud = mlx_png_file_to_image(so_long->mlx, WALL_RUD, &x, &y);
	tile->wall_lud = mlx_png_file_to_image(so_long->mlx, WALL_LUD, &x, &y);
	tile->wall_rl = mlx_png_file_to_image(so_long->mlx, WALL_RL, &x, &y);
	tile->wall_ud = mlx_png_file_to_image(so_long->mlx, WALL_UD, &x, &y);
	tile->wall_ru = mlx_png_file_to_image(so_long->mlx, WALL_RU, &x, &y);
	tile->wall_rd = mlx_png_file_to_image(so_long->mlx, WALL_RD, &x, &y);
	tile->wall_lu = mlx_png_file_to_image(so_long->mlx, WALL_LU, &x, &y);
	tile->wall_ld = mlx_png_file_to_image(so_long->mlx, WALL_LD, &x, &y);
	tile->wall_r = mlx_png_file_to_image(so_long->mlx, WALL_R, &x, &y);
	tile->wall_l = mlx_png_file_to_image(so_long->mlx, WALL_L, &x, &y);
	tile->wall_u = mlx_png_file_to_image(so_long->mlx, WALL_U, &x, &y);
	tile->wall_d = mlx_png_file_to_image(so_long->mlx, WALL_D, &x, &y);
	tile->wall = mlx_png_file_to_image(so_long->mlx, WALL, &x, &y);
}

void	prop_init(t_mlx *so_long, int x, int y)
{
	t_prop_lib	*prop;

	prop = &(so_long->prop_lid);
	prop->key = mlx_png_file_to_image(so_long->mlx, KEY, &x, &y);
	prop->berral = mlx_png_file_to_image(so_long->mlx, BERRAL, &x, &y);
	prop->rock = mlx_png_file_to_image(so_long->mlx, ROCK, &x, &y);
	prop->coin[0] = mlx_png_file_to_image(so_long->mlx, COIN00, &x, &y);
	prop->coin[1] = mlx_png_file_to_image(so_long->mlx, COIN01, &x, &y);
	prop->coin[2] = mlx_png_file_to_image(so_long->mlx, COIN02, &x, &y);
	prop->coin[3] = mlx_png_file_to_image(so_long->mlx, COIN03, &x, &y);
	prop->coin[4] = mlx_png_file_to_image(so_long->mlx, COIN04, &x, &y);
	prop->coin[5] = mlx_png_file_to_image(so_long->mlx, COIN05, &x, &y);
	prop->coin[6] = mlx_png_file_to_image(so_long->mlx, COIN06, &x, &y);
	prop->coin[7] = mlx_png_file_to_image(so_long->mlx, COIN07, &x, &y);
}

void	sprite_init(t_mlx *so_long)
{
	tile_init(so_long, 0, 0);
	prop_init(so_long, 0, 0);
}
