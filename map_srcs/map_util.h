/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:56:56 by junlee2           #+#    #+#             */
/*   Updated: 2022/09/27 10:40:41 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_UTIL_H
# define MAP_UTIL_H

# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include "get_next_line.h"
# include "mlx.h"
# include "libft.h"

typedef struct s_mapsetcnt
{
	int	floor;
	int	wall;
	int	coin;
	int	exit;
	int	player;
}	t_mapsetcnt;

char	**map_init(char *filename);
void	map_free(char	**map);
int		map_check_valid(char **map);

#endif
