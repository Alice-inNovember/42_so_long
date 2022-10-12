/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:13:25 by junlee2           #+#    #+#             */
/*   Updated: 2022/10/12 16:17:56 by junlee2          ###   ########seoul.kr  */
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
# include "libft.h"
# include "so_sprite.h"
# include "mlx.h"

# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_ESC	53

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
	int		floor;
	int		wall;
	int		coin;
	int		exit;
	int		player;
}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	key;
	int	coin;
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
}	t_data;

//util
void	err_exit(char *str, int errornum);

//map
void	map_init(char *filename, t_data *data);
int		map_check_valid(t_data *data);

//sprite
void	sprite_init(t_data *data);

#endif