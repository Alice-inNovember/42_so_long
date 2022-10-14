/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:19:44 by junlee2           #+#    #+#             */
/*   Updated: 2022/07/27 08:58:50 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char in)
{
	if (in == '\t' || in == '\n' || in == '\v')
		return (1);
	if (in == '\f' || in == '\r' || in == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		returni;
	int		sign;
	int		i;

	returni = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		returni *= 10;
		returni += str[i] - '0';
		i++;
	}
	return (returni * sign);
}
