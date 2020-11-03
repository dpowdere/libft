/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:42:21 by dpowdere          #+#    #+#             */
/*   Updated: 2020/11/03 15:56:31 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*cursor;
	char	ascii_char;

	len = 0;
	cursor = (char *)s;
	ascii_char = (char)c;
	while (*cursor++)
		++len;
	while (len > 0 && *--cursor != ascii_char)
		--len;
	if (*cursor == ascii_char)
		return (cursor);
	return (NULL);
}
