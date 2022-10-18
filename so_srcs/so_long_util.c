/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:26:11 by junlee2           #+#    #+#             */
/*   Updated: 2022/10/18 15:04:40 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_exit(char *str, int errornum)
{
	errno = errornum;
	perror(str);
	exit(EXIT_FAILURE);
}

void	player_init(t_data *data)
{
	data->player.coin = 0;
	data->player.face = 1;
	data->player.steps = 0;
	data->player.game_status = 0;
	data->player.key = 0;
}

void	background_init(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			render_background(data, x, y);
			x++;
		}
		y++;
	}
}