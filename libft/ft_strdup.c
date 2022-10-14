/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 09:10:36 by junlee2           #+#    #+#             */
/*   Updated: 2022/07/27 08:59:27 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	strl;
	char	*returnptr;
	int		i;

	strl = ft_strlen(s1);
	returnptr = (char *)malloc(strl + 1);
	if (!returnptr)
		return (0);
	i = 0;
	while (s1[i])
	{
		returnptr[i] = s1[i];
		i++;
	}
	returnptr[i] = 0;
	return (returnptr);
}
