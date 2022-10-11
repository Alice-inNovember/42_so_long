/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:12:49 by junlee2           #+#    #+#             */
/*   Updated: 2022/10/07 15:36:14 by junlee2          ###   ########seoul.kr  */
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

char	**map_init(char *filename)
{
	int		mapfd;
	char	**returnmap;

	mapfd = open(filename, O_RDONLY);
	returnmap = map_pars_re(mapfd, 0);
	close(mapfd);
	map_rmove_nl(returnmap);
	map_check_valid(returnmap);
	return (returnmap);
}
