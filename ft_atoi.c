/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:03:49 by dpowdere          #+#    #+#             */
/*   Updated: 2020/11/02 20:17:46 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	char			*s;
	int				sign;
	unsigned int	n;

	sign = 1;
	n = 0;
	s = (char *)nptr;
	while (*s == ' ' || *s == '\f' || *s == '\n' || *s == '\r'
			|| *s == '\t' || *s == '\v')
		++s;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		++s;
	}
	while (*s >= '0' && *s <= '9')
		n = n * 10 + (*s - '0');
	return (sign * n);
}
