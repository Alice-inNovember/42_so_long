/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:38:27 by junlee2           #+#    #+#             */
/*   Updated: 2022/07/27 08:59:35 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_isset(char a, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == a)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	s1len;
	int	f_trim;
	int	l_trim;

	s1len = ft_strlen(s1);
	f_trim = 0;
	l_trim = 0;
	while (ft_isset(s1[f_trim], set))
		f_trim++;
	while (ft_isset(s1[s1len - 1 - l_trim], set))
	{
		if (!(s1len - f_trim - l_trim >= 0))
			break ;
		l_trim ++;
	}
	return (ft_substr(s1, f_trim, s1len - f_trim - l_trim));
}
