/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 08:51:48 by junlee2           #+#    #+#             */
/*   Updated: 2022/07/27 08:58:55 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*returnptr;
	size_t			test;

	test = count * size;
	if (size != 0 && (test / size != count))
		return ((void *)0);
	returnptr = (unsigned char *)malloc(count * size);
	if (!returnptr)
		return ((void *)0);
	ft_bzero((void *)returnptr, count * size);
	return ((void *)returnptr);
}
