/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_display_score.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:15:44 by junlee2           #+#    #+#             */
/*   Updated: 2022/10/19 08:24:56 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_score(t_data *data)
{
	int	(*iput2window)(void *, void *, void *, int, int);
	int	steps;
	int	val;

	data->player.steps++;
	if (data->player.game_status == 0)
		(ft_putnbr_fd(data->player.steps, 1), ft_putstr_fd("\n", 1));
	steps = data->player.steps;
	iput2window = mlx_put_image_to_window;
	iput2window(data->mlx, data->mlx_win, data->font.ascii['\0'], 25 * 7, 0);
	iput2window(data->mlx, data->mlx_win, data->font.ascii['\0'], 25 * 8, 0);
	iput2window(data->mlx, data->mlx_win, data->font.ascii['\0'], 25 * 9, 0);
	iput2window(data->mlx, data->mlx_win, data->font.ascii['\0'], 25 * 10, 0);
	val = steps / 1000 + '0';
	iput2window(data->mlx, data->mlx_win, data->font.ascii[val], 25 * 7, 0);
	steps = steps % 1000;
	val = steps / 100 + '0';
	iput2window(data->mlx, data->mlx_win, data->font.ascii[val], 25 * 8, 0);
	steps = steps % 100;
	val = steps / 10 + '0';
	iput2window(data->mlx, data->mlx_win, data->font.ascii[val], 25 * 9, 0);
	steps = steps % 10;
	val = steps / 1 + '0';
	iput2window(data->mlx, data->mlx_win, data->font.ascii[val], 25 * 10, 0);
}

void	render_score(t_data *data)
{
	int	(*iput2window)(void *, void *, void *, int, int);

	iput2window = mlx_put_image_to_window;
	iput2window(data->mlx, data->mlx_win, data->font.ascii['\0'], 32 * 1, 0);
	iput2window(data->mlx, data->mlx_win, data->font.ascii['\0'], 32 * 2, 0);
	iput2window(data->mlx, data->mlx_win, data->font.ascii['\0'], 32 * 3, 0);
	iput2window(data->mlx, data->mlx_win, data->font.ascii['\0'], 32 * 4, 0);
	iput2window(data->mlx, data->mlx_win, data->font.ascii['\0'], 32 * 5, 0);
	iput2window(data->mlx, data->mlx_win, data->font.ascii['\0'], 32 * 6, 0);
	iput2window(data->mlx, data->mlx_win, data->font.ascii['S'], 25 * 1, 0);
	iput2window(data->mlx, data->mlx_win, data->font.ascii['T'], 25 * 2, 0);
	iput2window(data->mlx, data->mlx_win, data->font.ascii['E'], 25 * 3, 0);
	iput2window(data->mlx, data->mlx_win, data->font.ascii['P'], 25 * 4, 0);
	iput2window(data->mlx, data->mlx_win, data->font.ascii['S'], 25 * 5, 0);
	iput2window(data->mlx, data->mlx_win, data->font.ascii[':'], 25 * 6, 0);
	data->player.steps--;
	display_score(data);
}
