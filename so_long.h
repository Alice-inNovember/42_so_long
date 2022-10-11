/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:13:25 by junlee2           #+#    #+#             */
/*   Updated: 2022/10/11 11:23:24 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdio.h>
# include <errno.h>
# include "get_next_line.h"
# include "mlx.h"
# include "libft.h"

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

# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_ESC	53

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

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_mlx
{
	void			*mlx;
	void			*mlx_win;
	int				x;
	int				y;
	char			**map;
	t_tile_lib		tile_lib;
	t_prop_lib		prop_lib;
	t_player		player;
}	t_mlx;

typedef struct s_mapsetcnt
{
	int	floor;
	int	wall;
	int	coin;
	int	exit;
	int	player;
}	t_mapsetcnt;

//so_long_util
void	err_exit(char *str, int errornum);
void	map_size(t_mlx	*so_long);

int		display_window(t_mlx *so_long);

void	sprite_init(t_mlx *so_long);

char	**map_init(char *filename);
void	map_free(char	**map);
int		map_check_valid(char **map);

#endif