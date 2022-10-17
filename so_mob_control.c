/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_mob_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:05:20 by junlee2           #+#    #+#             */
/*   Updated: 2022/10/17 16:10:02 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mob_move(t_data *data, int x, int y)
{
	int	offset;
	int	offset_x;
	int	offset_y;

	offset_x = 0;
	offset_y = 0;
	if (rand() % 2)
		offset = 1;
	else
		offset = -1;
	if (rand() % 2)
		offset_x = offset;
	else
		offset_y = offset;
	if (ft_is_set(data->map.map[y + offset_y][x + offset_x], "1CEBM"))
		return ;
	else if (data->map.map[y + offset_y][x + offset_x] == 'P')
		mob_collide();
	data->map.map[y + offset_y][x + offset_x] = 'M';
	data->map.map[y][x] = '0';
}

void	mob_control(t_data *data, size_t tick)
{
	int	x;
	int	y;

	if (tick % 4000 != 0)
		return ;
	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (data->map.map[y][x] == 'M')
			{
				mob_move(data, x, y);
			}
			x++;
		}
		y++;
	}
}
