/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:45:16 by junlee2           #+#    #+#             */
/*   Updated: 2022/07/27 08:59:22 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_printer(int n, int fd)
{
	char	temp;

	temp = -(n % 10) + '0';
	if (n / 10 == 0)
	{
		write(fd, &temp, 1);
		return ;
	}
	ft_printer(n / 10, fd);
	write(fd, &temp, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 0)
		n *= -1;
	else
		write(fd, "-", 1);
	ft_printer(n, fd);
}
