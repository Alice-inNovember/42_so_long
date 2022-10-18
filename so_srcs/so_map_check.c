/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:12:49 by junlee2           #+#    #+#             */
/*   Updated: 2022/10/18 15:44:59 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_check_rectangle(t_data *data)
{
	size_t	x;
	size_t	y;
	size_t	i;

	y = 0;
	while (data->map.map[y])
		y++;
	if (y < 3)
		return ('N');
	x = ft_strlen(data->map.map[0]);
	i = 0;
	while (data->map.map[i])
	{
		if (x != ft_strlen(data->map.map[i]))
			return ('N');
		i++;
	}
	return ('Y');
}

int	map_charset_cnt(t_data *data, int y, int x)
{
	if (data->map.map[y][x] == '0')
		data->map.floor++;
	else if (data->map.map[y][x] == '1')
		data->map.wall++;
	else if (data->map.map[y][x] == 'C')
		data->map.coin++;
	else if (data->map.map[y][x] == 'E')
		data->map.exit++;
	else if (data->map.map[y][x] == 'P')
	{
		data->map.player++;
		data->player.x = x;
		data->player.y = y;
	}
	else
		return ('N');
	return ('Y');
}

int	map_check_charset(t_data *data, int y, int x)
{
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (map_charset_cnt(data, y, x) == 'N')
				return ('N');
			x++;
		}
		y++;
	}
	data->map.x = x;
	data->map.y = y;
	if (data->map.coin == 0)
		return ('N');
	else if (data->map.exit == 0)
		return ('N');
	else if (data->map.player == 0)
		return ('N');
	return ('Y');
}

int	map_check_wall(t_data *data)
{
	int	i;
	int	ylast;
	int	xlast;

	ylast = 0;
	while (data->map.map[ylast])
		ylast++;
	ylast--;
	i = 0;
	while (data->map.map[0][i])
	{
		if (data->map.map[0][i] != '1' || data->map.map[ylast][i] != '1')
			return ('N');
		i++;
	}
	xlast = ft_strlen(data->map.map[0]) - 1;
	i = 0;
	while (data->map.map[i])
	{
		if (data->map.map[i][0] != '1' || data->map.map[i][xlast] != '1')
			return ('N');
		i++;
	}
	return ('Y');
}

int	map_check_valid(t_data *data)
{
	if (map_check_rectangle(data) == 'N')
		err_exit("map is not rectangle\n", EINVAL);
	else if (map_check_charset(data, 0, 0) == 'N')
		err_exit("map set is not valid\n", EINVAL);
	else if (map_check_wall(data) == 'N')
		err_exit("map is not surround\n", EINVAL);
	return ('Y');
}
