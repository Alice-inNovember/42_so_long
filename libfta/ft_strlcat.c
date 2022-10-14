/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:00:09 by junlee2           #+#    #+#             */
/*   Updated: 2022/07/27 08:59:30 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	uppendstr(char *dest, char *src, size_t destl, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && i + destl + 1 < size)
	{
		dest[destl + i] = src[i];
		i++;
	}
	dest[destl + i] = 0;
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destl;
	size_t	srcl;

	destl = ft_strlen(dest);
	srcl = ft_strlen((char *)src);
	if (destl >= size)
		return (srcl + size);
	uppendstr(dest, (char *)src, destl, size);
	return (destl + srcl);
}
