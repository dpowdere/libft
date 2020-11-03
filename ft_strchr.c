/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:20:18 by dpowdere          #+#    #+#             */
/*   Updated: 2020/11/03 15:46:23 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*cursor;
	char	ascii_char;

	cursor = (char *)s;
	ascii_char = (char)c;
	while (*cursor != '\0' && *cursor != ascii_char)
		++cursor;
	if (*cursor == ascii_char)
		return (cursor);
	return (NULL);
}
