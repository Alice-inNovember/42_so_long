/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:12:49 by junlee2           #+#    #+#             */
/*   Updated: 2022/09/23 17:30:45 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "map_util.h"

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
		returnmap[cnt] = 0;
		return (returnmap);
	}
	returnmap = map_pars_re(mapfd, cnt + 1);
	if (!returnmap)
	{
		free (temp);
		return (0);
	}
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
}

char	**map_init(char *filename)
{
	int		mapfd;
	char	**returnmap;

	mapfd = open(filename, O_RDONLY);
	returnmap = map_pars_re(mapfd, 0);
	close(mapfd);
	map_rmove_nl(returnmap);
	if (map_check_valid(returnmap) == 'N')
	{
		map_free(returnmap);
		return (0);
	}
	return (returnmap);
}
