/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:35:22 by junlee2           #+#    #+#             */
/*   Updated: 2022/07/27 08:59:34 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	issame(char *str, char *to_find, size_t stri)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (to_find[i])
	{
		if (to_find[i] == str[i + stri])
			counter++;
		i++;
	}
	return (counter);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	flen;
	size_t	i;

	i = 0;
	flen = ft_strlen(needle);
	if (flen == 0)
		return ((char *)haystack);
	while (haystack[i] && i + flen <= len)
	{
		if (haystack[i] == needle[0])
			if (flen == issame((char *)haystack, (char *)needle, i))
				return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
