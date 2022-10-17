/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_sprite_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:52:24 by junlee2           #+#    #+#             */
/*   Updated: 2022/10/17 16:39:28 by junlee2          ###   ########seoul.kr  */
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
	data->wall.wall[0] = png2image(data->mlx, WALL, &x, &y);
	data->wall.wall[1] = png2image(data->mlx, WALL_R, &x, &y);
	data->wall.wall[2] = png2image(data->mlx, WALL_L, &x, &y);
	data->wall.wall[3] = png2image(data->mlx, WALL_RL, &x, &y);
	data->wall.wall[4] = png2image(data->mlx, WALL_U, &x, &y);
	data->wall.wall[5] = png2image(data->mlx, WALL_RU, &x, &y);
	data->wall.wall[6] = png2image(data->mlx, WALL_LU, &x, &y);
	data->wall.wall[7] = png2image(data->mlx, WALL_RLU, &x, &y);
	data->wall.wall[8] = png2image(data->mlx, WALL_D, &x, &y);
	data->wall.wall[9] = png2image(data->mlx, WALL_RD, &x, &y);
	data->wall.wall[10] = png2image(data->mlx, WALL_LD, &x, &y);
	data->wall.wall[11] = png2image(data->mlx, WALL_RLD, &x, &y);
	data->wall.wall[12] = png2image(data->mlx, WALL_UD, &x, &y);
	data->wall.wall[13] = png2image(data->mlx, WALL_RUD, &x, &y);
	data->wall.wall[14] = png2image(data->mlx, WALL_LUD, &x, &y);
	data->wall.wall[15] = png2image(data->mlx, WALL_RLUD, &x, &y);
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

void	player_image_init(t_data *data)
{
	void	*(*png2image)(void *, char *, int *, int *);
	int		x;
	int		y;

	png2image = mlx_png_file_to_image;
	data->player.img_r[0] = png2image(data->mlx, PLAYER00R, &x, &y);
	data->player.img_r[1] = png2image(data->mlx, PLAYER00R, &x, &y);
	data->player.img_r[2] = png2image(data->mlx, PLAYER01R, &x, &y);
	data->player.img_r[3] = png2image(data->mlx, PLAYER01R, &x, &y);
	data->player.img_r[4] = png2image(data->mlx, PLAYER02R, &x, &y);
	data->player.img_r[5] = png2image(data->mlx, PLAYER02R, &x, &y);
	data->player.img_r[6] = png2image(data->mlx, PLAYER03R, &x, &y);
	data->player.img_r[7] = png2image(data->mlx, PLAYER03R, &x, &y);
	data->player.img_l[0] = png2image(data->mlx, PLAYER00L, &x, &y);
	data->player.img_l[1] = png2image(data->mlx, PLAYER00L, &x, &y);
	data->player.img_l[2] = png2image(data->mlx, PLAYER01L, &x, &y);
	data->player.img_l[3] = png2image(data->mlx, PLAYER01L, &x, &y);
	data->player.img_l[4] = png2image(data->mlx, PLAYER02L, &x, &y);
	data->player.img_l[5] = png2image(data->mlx, PLAYER02L, &x, &y);
	data->player.img_l[6] = png2image(data->mlx, PLAYER03L, &x, &y);
	data->player.img_l[7] = png2image(data->mlx, PLAYER03L, &x, &y);
}

void	mob_image_init(t_data *data)
{
	void	*(*png2image)(void *, char *, int *, int *);
	int		x;
	int		y;

	png2image = mlx_png_file_to_image;
	data->prop.mob[0] = png2image(data->mlx, MOB00, &x, &y);
	data->prop.mob[1] = png2image(data->mlx, MOB00, &x, &y);
	data->prop.mob[2] = png2image(data->mlx, MOB01, &x, &y);
	data->prop.mob[3] = png2image(data->mlx, MOB01, &x, &y);
	data->prop.mob[4] = png2image(data->mlx, MOB02, &x, &y);
	data->prop.mob[5] = png2image(data->mlx, MOB02, &x, &y);
	data->prop.mob[6] = png2image(data->mlx, MOB03, &x, &y);
	data->prop.mob[7] = png2image(data->mlx, MOB03, &x, &y);
}

void	sprite_init(t_data *data)
{
	player_image_init(data);
	wall_image_init(data);
	prop_image_init(data);
	mob_image_init(data);
	font_ascii_init_1(data);
	font_ascii_init_2(data);
}
