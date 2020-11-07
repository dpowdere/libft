/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:18:51 by dpowdere          #+#    #+#             */
/*   Updated: 2020/11/07 14:43:20 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static unsigned int	ft___count_digits(int n)
{
	unsigned int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		n /= 10;
		++count;
	}
	return (count);
}

char				*ft_itoa(int n)
{
	unsigned int	n_digits;
	char			*str;

	n_digits = ft___count_digits(n);
	str = (char *)malloc((n_digits + (n < 0 ? 1 : 0) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
		*str = '-';
	str += n_digits;
	*str = '\0';
	while (n_digits-- > 0)
	{
		*--str = '0' + n % 10 * (n < 0 ? -1 : 1);
		n /= 10;
	}
	return (str);
}
