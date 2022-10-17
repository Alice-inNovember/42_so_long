/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_display_score.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:15:44 by junlee2           #+#    #+#             */
/*   Updated: 2022/10/17 16:41:04 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	font_init(t_data *data)
{
	(void)data;
}

void	display_score(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, 0, 0, 0);
}
