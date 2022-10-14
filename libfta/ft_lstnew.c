/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:10:30 by junlee2           #+#    #+#             */
/*   Updated: 2022/07/27 08:59:15 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*return_tl;

	return_tl = (void *)malloc(sizeof(t_list));
	if (!return_tl)
		return (0);
	return_tl -> content = content;
	return_tl -> next = (void *)0;
	return (return_tl);
}
