/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:12:49 by junlee2           #+#    #+#             */
/*   Updated: 2022/10/25 09:26:11 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_pars_re(int mapfd, int cnt)
{
	char	**returnmap;
	char	*temp;

	temp = get_next_line(mapfd);
	if (!temp)
	{
		if (!cnt)
			return (0);
		returnmap = (char **)malloc(sizeof(char *) * (cnt + 1));
		if (!returnmap)
		{
			perror("map_pars malloc : ");
			exit(errno);
		}
		returnmap[cnt] = 0;
		return (returnmap);
	}
	returnmap = map_pars_re(mapfd, cnt + 1);
	if (!returnmap)
		return (0);
	returnmap[cnt] = temp;
	return (returnmap);
}

void	map_rmove_nl(char	**map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\n')
				map[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	map_free(char	**map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free (map);
	map = 0;
}

void	map_val_set(t_data *data)
{
	data->map.player = 0;
	data->map.floor = 0;
	data->map.wall = 0;
	data->map.coin = 0;
	data->map.exit = 0;
}

void	map_init(char *filename, t_data *data)
{
	int		mapfd;
	size_t	len;

	len = ft_strlen(filename);
	if (ft_strncmp(&filename[len - 4], ".ber", 4))
		err_exit("Error\nWrong file extension : use < .ber >\n", EINVAL);
	map_val_set(data);
	mapfd = open(filename, O_RDONLY);
	if (mapfd == -1)
		err_exit("Error\nopen", errno);
	data->map.map = map_pars_re(mapfd, 0);
	if (!data->map.map)
		err_exit("Error\nMap not valid or malloc err\n", 0);
	close(mapfd);
	map_rmove_nl(data->map.map);
	map_check_valid(data);
}
