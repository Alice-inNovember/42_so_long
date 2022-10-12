/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_sprite_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:52:24 by junlee2           #+#    #+#             */
/*   Updated: 2022/10/12 16:14:38 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_image_init(t_data *data)
{
	void	*(*png2image)(void *, char *, int *, int *);
	int		x;
	int		y;

	png2image = mlx_png_file_to_image;
	data->wall.land[0] = png2image(data->mlx, LAND_00, &x, &y);
	data->wall.land[1] = png2image(data->mlx, LAND_01, &x, &y);
	data->wall.wall_rlud = png2image(data->mlx, WALL_RLUD, &x, &y);
	data->wall.wall_rlu = png2image(data->mlx, WALL_RLU, &x, &y);
	data->wall.wall_rld = png2image(data->mlx, WALL_RLD, &x, &y);
	data->wall.wall_rud = png2image(data->mlx, WALL_RUD, &x, &y);
	data->wall.wall_lud = png2image(data->mlx, WALL_LUD, &x, &y);
	data->wall.wall_rl = png2image(data->mlx, WALL_RL, &x, &y);
	data->wall.wall_ud = png2image(data->mlx, WALL_UD, &x, &y);
	data->wall.wall_ru = png2image(data->mlx, WALL_RU, &x, &y);
	data->wall.wall_rd = png2image(data->mlx, WALL_RD, &x, &y);
	data->wall.wall_lu = png2image(data->mlx, WALL_LU, &x, &y);
	data->wall.wall_ld = png2image(data->mlx, WALL_LD, &x, &y);
	data->wall.wall_r = png2image(data->mlx, WALL_R, &x, &y);
	data->wall.wall_l = png2image(data->mlx, WALL_L, &x, &y);
	data->wall.wall_u = png2image(data->mlx, WALL_U, &x, &y);
	data->wall.wall_d = png2image(data->mlx, WALL_D, &x, &y);
	data->wall.wall = png2image(data->mlx, WALL, &x, &y);
}

void	prop_image_init(t_data *data)
{
	void	*(*png2image)(void *, char *, int *, int *);
	int		x;
	int		y;

	png2image = mlx_png_file_to_image;
	data->prop.key = png2image(data->mlx, KEY, &x, &y);
	data->prop.berral = png2image(data->mlx, BERRAL, &x, &y);
	data->prop.rock = png2image(data->mlx, ROCK, &x, &y);
	data->prop.coin[0] = png2image(data->mlx, COIN00, &x, &y);
	data->prop.coin[1] = png2image(data->mlx, COIN01, &x, &y);
	data->prop.coin[2] = png2image(data->mlx, COIN02, &x, &y);
	data->prop.coin[3] = png2image(data->mlx, COIN03, &x, &y);
	data->prop.coin[4] = png2image(data->mlx, COIN04, &x, &y);
	data->prop.coin[5] = png2image(data->mlx, COIN05, &x, &y);
	data->prop.coin[6] = png2image(data->mlx, COIN06, &x, &y);
	data->prop.coin[7] = png2image(data->mlx, COIN07, &x, &y);
}

void	sprite_init(t_data *data)
{
	wall_image_init(data);
	prop_image_init(data);
}
