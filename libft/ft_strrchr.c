/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:23:51 by junlee2           #+#    #+#             */
/*   Updated: 2022/07/27 08:59:34 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	slen;

	slen = ft_strlen(s);
	while (0 < slen)
	{
		if ((char)s[slen] == (char)c)
			return ((char *)&s[slen]);
		slen--;
	}
	if ((char)s[slen] == (char)c)
		return ((char *)&s[slen]);
	return (0);
}
