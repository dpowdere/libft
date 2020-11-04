/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:13:31 by dpowdere          #+#    #+#             */
/*   Updated: 2020/11/04 16:21:09 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*memset(void *s, int c, size_t n)
{
	unsigned char *mem;

	mem = (unsigned char *)s;
	while (n-- > 0)
		*mem++ = (unsigned char)c;
	return (s);
}
