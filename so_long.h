/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:13:25 by junlee2           #+#    #+#             */
/*   Updated: 2022/09/26 12:52:49 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include "get_next_line.h"
# include "mlx.h"
# include "libft.h"
# include "map_util.h"
# include "sprite.h"

typedef struct s_mlx
{
	void			*mlx;
	void			*mlx_win;
	char			**map;
	t_sprite_lib	sprite_lib;
}	t_mlx;

#endif