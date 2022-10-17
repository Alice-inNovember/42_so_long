/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_mob_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:05:20 by junlee2           #+#    #+#             */
/*   Updated: 2022/10/17 14:02:08 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mob_move(t_data *data, int x, int y)
{
	int	option_xy;
	int	option_pm;
	int	offset;

	option_xy = rand() % 2;
	option_pm = rand() % 2;
	if (option_pm == 0)
		offset = 1;
	else
		offset = -1;
	if (option_xy == 1)
	{
		if (ft_is_set(data->map.map[y + offset][x], "1CEBM"))
			return ;
		data->map.map[y + offset][x] = 'M';
	}
	else
	{
		if (ft_is_set(data->map.map[y][x + offset], "1CEBM"))
			return ;
		data->map.map[y][x + offset] = 'M';
	}
	data->map.map[y][x] = '0';
}

void	mob_control(t_data *data, int op1, int op2)
{
	int	x;
	int	y;

	if (!op1 && !op2)
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
