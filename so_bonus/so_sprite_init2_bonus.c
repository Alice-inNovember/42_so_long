/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_sprite_init2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:52:24 by junlee2           #+#    #+#             */
/*   Updated: 2022/10/18 15:22:48 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	font_ascii_init_1(t_data *data, int *x, int *y)
{
	void	*(*png2image)(void *, char *, int *, int *);

	png2image = mlx_png_file_to_image;
	data->font.ascii['0'] = png2image(data->mlx, FONT_0, x, y);
	data->font.ascii['1'] = png2image(data->mlx, FONT_1, x, y);
	data->font.ascii['2'] = png2image(data->mlx, FONT_2, x, y);
	data->font.ascii['3'] = png2image(data->mlx, FONT_3, x, y);
	data->font.ascii['4'] = png2image(data->mlx, FONT_4, x, y);
	data->font.ascii['5'] = png2image(data->mlx, FONT_5, x, y);
	data->font.ascii['6'] = png2image(data->mlx, FONT_6, x, y);
	data->font.ascii['7'] = png2image(data->mlx, FONT_7, x, y);
	data->font.ascii['8'] = png2image(data->mlx, FONT_8, x, y);
	data->font.ascii['9'] = png2image(data->mlx, FONT_9, x, y);
	data->font.ascii[':'] = png2image(data->mlx, FONT_COLON, x, y);
	data->font.ascii['\0'] = png2image(data->mlx, FONT_VOID, x, y);
	data->font.ascii['A'] = png2image(data->mlx, FONT_A, x, y);
	data->font.ascii['B'] = png2image(data->mlx, FONT_B, x, y);
	data->font.ascii['C'] = png2image(data->mlx, FONT_C, x, y);
	data->font.ascii['D'] = png2image(data->mlx, FONT_D, x, y);
	data->font.ascii['E'] = png2image(data->mlx, FONT_E, x, y);
	data->font.ascii['F'] = png2image(data->mlx, FONT_F, x, y);
	data->font.ascii['G'] = png2image(data->mlx, FONT_G, x, y);
}

void	font_ascii_init_2(t_data *data, int *x, int *y)
{
	void	*(*png2image)(void *, char *, int *, int *);

	png2image = mlx_png_file_to_image;
	data->font.ascii['H'] = png2image(data->mlx, FONT_H, x, y);
	data->font.ascii['I'] = png2image(data->mlx, FONT_I, x, y);
	data->font.ascii['J'] = png2image(data->mlx, FONT_J, x, y);
	data->font.ascii['K'] = png2image(data->mlx, FONT_K, x, y);
	data->font.ascii['L'] = png2image(data->mlx, FONT_L, x, y);
	data->font.ascii['M'] = png2image(data->mlx, FONT_M, x, y);
	data->font.ascii['N'] = png2image(data->mlx, FONT_N, x, y);
	data->font.ascii['O'] = png2image(data->mlx, FONT_O, x, y);
	data->font.ascii['P'] = png2image(data->mlx, FONT_P, x, y);
	data->font.ascii['Q'] = png2image(data->mlx, FONT_Q, x, y);
	data->font.ascii['R'] = png2image(data->mlx, FONT_R, x, y);
	data->font.ascii['S'] = png2image(data->mlx, FONT_S, x, y);
	data->font.ascii['T'] = png2image(data->mlx, FONT_T, x, y);
	data->font.ascii['U'] = png2image(data->mlx, FONT_U, x, y);
	data->font.ascii['V'] = png2image(data->mlx, FONT_V, x, y);
	data->font.ascii['W'] = png2image(data->mlx, FONT_W, x, y);
	data->font.ascii['X'] = png2image(data->mlx, FONT_X, x, y);
	data->font.ascii['Y'] = png2image(data->mlx, FONT_Y, x, y);
	data->font.ascii['Z'] = png2image(data->mlx, FONT_Z, x, y);
}
