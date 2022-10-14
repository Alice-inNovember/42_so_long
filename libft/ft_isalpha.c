/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:36:45 by junlee2           #+#    #+#             */
/*   Updated: 2022/07/27 08:58:59 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_isupper(int in)
{
	if (in < 'A' || in > 'Z')
		return (0);
	return (1);
}

int	ft_islower(int in)
{
	if (in < 'a' || in > 'z')
		return (0);
	return (1);
}

int	ft_isalpha(int in)
{
	if (ft_isupper(in))
		return (1);
	if (ft_islower(in))
		return (2);
	else
		return (0);
}
