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
	unsigned int	abs_value;

	if (fd < 0)
		return ;
	abs_value = (unsigned int)(n < 0 ? -n : n);
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (abs_value / 10u > 0)
		ft_putnbr_fd((int)(abs_value / 10u), fd);
	else
		ft_putchar_fd('0' + abs_value, fd);
}