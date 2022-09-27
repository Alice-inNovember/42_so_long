/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:41:29 by junlee2           #+#    #+#             */
/*   Updated: 2022/09/27 12:44:33 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include "mlx.h"

# define LAND_00	"./sprite_file/LAND/LAND00.png"
# define LAND_01	"./sprite_file/LAND/LAND01.png"
# define WALL_DE	"./sprite_file/WALL/WALL_DE.png"
# define WALL_DL	"./sprite_file/WALL/WALL_DL.png"
# define WALL_DR	"./sprite_file/WALL/WALL_DR.png"
# define WALL_H		"./sprite_file/WALL/WALL_H.png"
# define WALL_HL	"./sprite_file/WALL/WALL_HL.png"
# define WALL_HR	"./sprite_file/WALL/WALL_HR.png"
# define WALL_LE	"./sprite_file/WALL/WALL_LE.png"
# define WALL_RE	"./sprite_file/WALL/WALL_RE.png"
# define WALL_UE	"./sprite_file/WALL/WALL_UE.png"
# define WALL_UL	"./sprite_file/WALL/WALL_UL.png"
# define WALL_UR	"./sprite_file/WALL/WALL_UR.png"
# define WALL_V		"./sprite_file/WALL/WALL_V.png"
# define WALL_VD	"./sprite_file/WALL/WALL_VD.png"
# define WALL_VU	"./sprite_file/WALL/WALL_VU.png"

# define KEY		"./sprite_file/PROP/KEY.png"
# define BERRAL		"./sprite_file/PROP/BERRAL.png"
# define ROCK		"./sprite_file/PROP/ROCK.png"
# define COIN00		"./sprite_file/PROP/COIN00.png"
# define COIN01		"./sprite_file/PROP/COIN01.png"
# define COIN02		"./sprite_file/PROP/COIN02.png"
# define COIN03		"./sprite_file/PROP/COIN03.png"
# define COIN04		"./sprite_file/PROP/COIN04.png"
# define COIN05		"./sprite_file/PROP/COIN05.png"
# define COIN06		"./sprite_file/PROP/COIN06.png"
# define COIN07		"./sprite_file/PROP/COIN07.png"

typedef struct s_tile_lib
{
	void	*land[2];
	void	*wall_de;
	void	*wall_dl;
	void	*wall_dr;
	void	*wall_h;
	void	*wall_hl;
	void	*wall_hr;
	void	*wall_le;
	void	*wall_re;
	void	*wall_ue;
	void	*wall_ul;
	void	*wall_ur;
	void	*wall_v;
	void	*wall_vd;
	void	*wall_vu;
}	t_tile_lib;

typedef struct s_prop_lib
{
	void	*key;
	void	*berral;
	void	*rock;
	void	*coin[8];
}	t_prop_lib;

typedef struct s_mlx
{
	void			*mlx;
	void			*mlx_win;
	int				x;
	int				y;
	char			**map;
	t_tile_lib		tile_lib;
	t_prop_lib		prop_lid;
}	t_mlx;

void	sprite_init(t_mlx *so_long);

#endif