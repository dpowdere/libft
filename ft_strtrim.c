/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:49:51 by dpowdere          #+#    #+#             */
/*   Updated: 2020/11/20 23:55:15 by dpowdere         ###   ########.fr       */
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
	trimmed = (char *)malloc((end - start + 2) * sizeof(char));
	if (!trimmed)
		return (NULL);
	*(trimmed + (++end - start)) = '\0';
	while (--end >= start)
		*(trimmed + (end - start)) = *end;
	return (trimmed);
}
