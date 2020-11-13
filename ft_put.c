/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:54:00 by dpowdere          #+#    #+#             */
/*   Updated: 2020/11/06 14:06:05 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}

void	ft_putendl_fd(char *s, int fd)
{
	if (fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		sign;
	int		power10;
	int		x;
	char	c;

	if (fd < 0)
		return ;
	if (n < 0)
		write(fd, "-", 1);
	sign = (n < 0 ? -1 : 1);
	power10 = 1;
	x = n;
	while ((x /= 10) != 0)
		power10 *= 10;
	while (power10 != 0)
	{
		x = n / power10;
		c = (unsigned char)('0' + x * sign);
		n %= power10;
		power10 /= 10;
		write(fd, &c, 1);
	}
}
