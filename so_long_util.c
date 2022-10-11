/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:26:11 by junlee2           #+#    #+#             */
/*   Updated: 2022/10/11 10:31:55 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_exit(char *str, int errornum)
{
	errno = errornum;
	perror(str);
	exit(EXIT_FAILURE);
}

void	map_size(t_mlx	*so_long)
{
	so_long->x = 0;
	so_long->y = 0;
	while (so_long->map[so_long->y])
		so_long->y++;
	while (so_long->map[0][so_long->x])
		so_long->x++;
	so_long->x--;
	so_long->y--;
}
