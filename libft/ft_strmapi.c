/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:48:20 by junlee2           #+#    #+#             */
/*   Updated: 2022/07/27 08:59:32 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*returns;
	int		i;

	returns = (char *)malloc(ft_strlen(s) + 1);
	if (!returns)
		return (0);
	i = 0;
	while (s[i])
	{
		returns[i] = f(i, s[i]);
		i++;
	}
	returns[i] = 0;
	return (returns);
}
