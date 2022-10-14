/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_sprite.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:00:07 by junlee2           #+#    #+#             */
/*   Updated: 2022/10/14 14:58:59 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_SPRITE_H
# define SO_SPRITE_H

# define LAND_00	"./file_sprite/LAND/LAND00.png"
# define LAND_01	"./file_sprite/LAND/LAND01.png"
# define WALL		"./file_sprite/WALL/WALL.png"
# define WALL_RLUD	"./file_sprite/WALL/WALL_RLUD.png"
# define WALL_RLU	"./file_sprite/WALL/WALL_RLU.png"
# define WALL_RLD	"./file_sprite/WALL/WALL_RLD.png"
# define WALL_RUD	"./file_sprite/WALL/WALL_RUD.png"
# define WALL_LUD	"./file_sprite/WALL/WALL_LUD.png"
# define WALL_RL	"./file_sprite/WALL/WALL_RL.png"
# define WALL_UD	"./file_sprite/WALL/WALL_UD.png"
# define WALL_RU	"./file_sprite/WALL/WALL_RU.png"
# define WALL_RD	"./file_sprite/WALL/WALL_RD.png"
# define WALL_LU	"./file_sprite/WALL/WALL_LU.png"
# define WALL_LD	"./file_sprite/WALL/WALL_LD.png"
# define WALL_R		"./file_sprite/WALL/WALL_R.png"
# define WALL_L		"./file_sprite/WALL/WALL_L.png"
# define WALL_U		"./file_sprite/WALL/WALL_U.png"
# define WALL_D		"./file_sprite/WALL/WALL_D.png"

# define KEY		"./file_sprite/PROP/KEY.png"
# define BERRAL		"./file_sprite/PROP/BERRAL.png"
# define ROCK		"./file_sprite/PROP/ROCK.png"
# define COIN00		"./file_sprite/PROP/COIN00.png"
# define COIN01		"./file_sprite/PROP/COIN01.png"
# define COIN02		"./file_sprite/PROP/COIN02.png"
# define COIN03		"./file_sprite/PROP/COIN03.png"
# define COIN04		"./file_sprite/PROP/COIN04.png"
# define COIN05		"./file_sprite/PROP/COIN05.png"
# define COIN06		"./file_sprite/PROP/COIN06.png"
# define COIN07		"./file_sprite/PROP/COIN07.png"

# define PLAYER00R	"./file_sprite/PLAYER/PLAYER00R.png"
# define PLAYER01R	"./file_sprite/PLAYER/PLAYER01R.png"
# define PLAYER02R	"./file_sprite/PLAYER/PLAYER02R.png"
# define PLAYER03R	"./file_sprite/PLAYER/PLAYER03R.png"
# define PLAYER04R	"./file_sprite/PLAYER/PLAYER04R.png"
# define PLAYER05R	"./file_sprite/PLAYER/PLAYER05R.png"
# define PLAYER06R	"./file_sprite/PLAYER/PLAYER06R.png"
# define PLAYER07R	"./file_sprite/PLAYER/PLAYER07R.png"

typedef struct s_wall
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
}	t_wall;

typedef struct s_prop
{
	void	*key;
	void	*berral;
	void	*rock;
	void	*coin[8];
}	t_prop;

#endif
