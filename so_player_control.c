/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_player_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:41:09 by junlee2           #+#    #+#             */
/*   Updated: 2022/10/17 16:14:23 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	exit_key(t_data *data)
{
	if (data->player.coin == data->map.coin)
		exit(0);
	else
		return (-1);
}

int	b_move(t_data *data, int x, int y)
{
	int	offset_x;
	int	offset_y;

	offset_x = data->player.x + x;
	offset_y = data->player.y + y;
	if (ft_is_set(data->map.map[offset_y + y][offset_x + x], "1CEB"))
		return (-1);
	data->map.map[offset_y + y][offset_x + x] = 'B';
	return (0);
}

void	mob_collide(void)
{
	ft_putstr_fd("DON'T PANIC!\n", 1);
	exit(EXIT_SUCCESS);
}

void	player_control(t_data *data, int x, int y)
{
	int	offset_x;
	int	offset_y;

	offset_x = data->player.x + x;
	offset_y = data->player.y + y;
	if (data->map.map[offset_y][offset_x] == 'M')
		mob_collide();
	else if (data->map.map[data->player.y][data->player.x] == 'M')
		mob_collide();
	else if (data->map.map[offset_y][offset_x] == '1')
		return ;
	else if (data->map.map[offset_y][offset_x] == 'C')
		data->player.coin++;
	else if (data->map.map[offset_y][offset_x] == 'E' && exit_key(data))
		return ;
	else if (data->map.map[offset_y][offset_x] == 'B' && b_move(data, x, y))
		return ;
	data->map.map[data->player.y][data->player.x] = '0';
	data->map.map[offset_y][offset_x] = 'P';
	data->player.y += y;
	data->player.x += x;
}
