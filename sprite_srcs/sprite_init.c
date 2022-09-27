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
	tile->wall_de = mlx_png_file_to_image(so_long->mlx, WALL_DE, &x, &y);
	tile->wall_dl = mlx_png_file_to_image(so_long->mlx, WALL_DL, &x, &y);
	tile->wall_dr = mlx_png_file_to_image(so_long->mlx, WALL_DR, &x, &y);
	tile->wall_h = mlx_png_file_to_image(so_long->mlx, WALL_H, &x, &y);
	tile->wall_hl = mlx_png_file_to_image(so_long->mlx, WALL_HL, &x, &y);
	tile->wall_hr = mlx_png_file_to_image(so_long->mlx, WALL_HR, &x, &y);
	tile->wall_le = mlx_png_file_to_image(so_long->mlx, WALL_LE, &x, &y);
	tile->wall_re = mlx_png_file_to_image(so_long->mlx, WALL_RE, &x, &y);
	tile->wall_ue = mlx_png_file_to_image(so_long->mlx, WALL_UE, &x, &y);
	tile->wall_ul = mlx_png_file_to_image(so_long->mlx, WALL_UL, &x, &y);
	tile->wall_ur = mlx_png_file_to_image(so_long->mlx, WALL_UR, &x, &y);
	tile->wall_v = mlx_png_file_to_image(so_long->mlx, WALL_V, &x, &y);
	tile->wall_vd = mlx_png_file_to_image(so_long->mlx, WALL_VD, &x, &y);
	tile->wall_vu = mlx_png_file_to_image(so_long->mlx, WALL_VU, &x, &y);
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
