/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:13:25 by junlee2           #+#    #+#             */
/*   Updated: 2022/10/18 15:04:28 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
//libs
# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdio.h>
# include <errno.h>
//bonus
# include <time.h>
# include <stdlib.h>
//mylibs
# include "get_next_line.h"
# include "libft.h"
# include "so_sprite.h"
# include "mlx.h"

# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_ESC	53

# define ON_KEYDOWN		2
# define ON_KEYUP		3
# define ON_MOUSEDOWN	4
# define ON_MOUSEUP		5
# define ON_MOUSEMOVE	6
# define ON_EXPOSE		12
# define ON_DESTROY		17

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
	int		x_cordset;
	int		floor;
	int		wall;
	int		coin;
	int		exit;
	int		player;
}	t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		key;
	int		coin;
	int		face;
	int		steps;
	int		game_status;
	void	*img_r[8];
	void	*img_l[8];
}	t_player;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	int			win_x;
	int			win_y;
	t_map		map;
	t_player	player;
	t_wall		wall;
	t_prop		prop;
	t_font		font;
}	t_data;

//util
void	err_exit(char *str, int errornum);
void	player_init(t_data *data);
void	background_init(t_data *data);

//map
void	map_init(char *filename, t_data *data);
int		map_check_valid(t_data *data);

//sprite
void	sprite_init(t_data *data);
void	font_ascii_init_1(t_data *data, int *x, int *y);
void	font_ascii_init_2(t_data *data, int *x, int *y);

//display
int		render_window(t_data *data);
void	render_background(t_data *data, int x, int y);
void	render_score(t_data *data);
void	display_score(t_data *data);

//player_cnt
void	player_control(t_data *data, int x, int y);
int		ft_is_set(char c, char *set);
void	mob_collide(t_data *data);
void	mob_control(t_data *data, size_t tick);

#endif