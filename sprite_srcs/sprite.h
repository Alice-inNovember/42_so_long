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
# define WALL		"./sprite_file/WALL/WALL.png"
# define WALL_RLUD	"./sprite_file/WALL/WALL_RLUD.png"
# define WALL_RLU	"./sprite_file/WALL/WALL_RLU.png"
# define WALL_RLD	"./sprite_file/WALL/WALL_RLD.png"
# define WALL_RUD	"./sprite_file/WALL/WALL_RUD.png"
# define WALL_LUD	"./sprite_file/WALL/WALL_LUD.png"
# define WALL_RL	"./sprite_file/WALL/WALL_RL.png"
# define WALL_UD	"./sprite_file/WALL/WALL_UD.png"
# define WALL_RU	"./sprite_file/WALL/WALL_RU.png"
# define WALL_RD	"./sprite_file/WALL/WALL_RD.png"
# define WALL_LU	"./sprite_file/WALL/WALL_LU.png"
# define WALL_LD	"./sprite_file/WALL/WALL_LD.png"
# define WALL_R		"./sprite_file/WALL/WALL_R.png"
# define WALL_L		"./sprite_file/WALL/WALL_L.png"
# define WALL_U		"./sprite_file/WALL/WALL_U.png"
# define WALL_D		"./sprite_file/WALL/WALL_D.png"

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
	void	*wall_rlud;
	void	*wall_rlu;
	void	*wall_rld;
	void	*wall_rud;
	void	*wall_lud;
	void	*wall_rl;
	void	*wall_ud;
	void	*wall_ru;
	void	*wall_rd;
	void	*wall_lu;
	void	*wall_ld;
	void	*wall_r;
	void	*wall_l;
	void	*wall_u;
	void	*wall_d;
	void	*wall;
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