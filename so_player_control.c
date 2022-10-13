/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_player_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:41:09 by junlee2           #+#    #+#             */
/*   Updated: 2022/10/13 13:12:56 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_control(int keycode, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (keycode == KEY_W)
		y = -1;
	if (keycode == KEY_A)
		x = -1;
	if (keycode == KEY_S)
		y = 1;
	if (keycode == KEY_D)
		x = 1;
	if (data->map.map[data->player.y + y][data->player.x + x] == '1')
		return ;
	if (data->map.map[data->player.y + y][data->player.x + x] == 'C')
		data->player.coin++;
	data->map.map[data->player.y][data->player.x] = '0';
	data->map.map[data->player.y + y][data->player.x + x] = 'P';
	data->player.y += y;
	data->player.x += x;
}
