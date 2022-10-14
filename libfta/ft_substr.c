/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:18:21 by junlee2           #+#    #+#             */
/*   Updated: 2022/07/27 08:59:36 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*returns;
	size_t	i;
	size_t	malloc_len;

	if ((unsigned int)ft_strlen(s) < start)
	{
		returns = (char *)malloc(1);
		returns[0] = 0;
		return (returns);
	}
	malloc_len = ft_strlen(s);
	if (len < malloc_len)
		malloc_len = len;
	returns = (char *)malloc(malloc_len + 1);
	if (!returns)
		return (0);
	i = 0;
	while (s[start + i] && i < len)
	{
		returns[i] = s[start + i];
		i++;
	}
	returns[i] = 0;
	return (returns);
}
