/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:41:29 by junlee2           #+#    #+#             */
/*   Updated: 2022/09/26 15:17:19 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include "mlx.h"

# define FLOOR_01 "./sprite_file/floor/floor_1.png"
// # define FLOOR_02 ""
// # define FLOOR_03 ""
// # define FLOOR_04 ""
// # define FLOOR_05 ""
// # define FLOOR_LEFT ""
// # define FLOOR_RIGHT ""
// # define FLOOR_TOP ""
// # define FLOOR_T_LEFT ""
// # define FLOOR_T_RIGHT ""
// # define FLOOR_C_LEFT ""
// # define FLOOR_C_RIGHT ""
# define NEXTLEVEL "./sprite_file/floor/stair_nextlevel.png"
# define WALL_01 "./sprite_file/wall/wall_1.png"

typedef struct s_sprite_lib
{
	void	*floor_01;
	void	*floor_02;
	void	*floor_03;
	void	*floor_04;
	void	*floor_05;
	void	*floor_left;
	void	*floor_right;
	void	*floor_top;
	void	*floor_t_left;
	void	*floor_t_right;
	void	*floor_c_left;
	void	*floor_c_right;
	void	*nextlevel;
	void	*wall_01;
}	t_sprite_lib;

void	sprite_init(void *mlx, t_sprite_lib *sprite_lib);

#endif