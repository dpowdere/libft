/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:49:51 by dpowdere          #+#    #+#             */
/*   Updated: 2020/11/24 16:29:29 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char *start;
	char *end;
	char *trimmed;

	if (!s1)
		return (NULL);
	start = (char *)s1;
	while (*start && set && ft_strchr(set, *start))
		++start;
	end = start;
	while (*end && *(end + 1))
		++end;
	while (end > start && set && ft_strchr(set, *end))
		--end;
	trimmed = (char *)malloc(sizeof(char) * (!*start ? 1 : end - start + 2));
	if (!trimmed)
		return (NULL);
	++end;
	if (*start)
		*(end - start + trimmed) = '\0';
	while (--end >= start)
		*(end - start + trimmed) = *end;
	return (trimmed);
}
