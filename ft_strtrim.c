/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:49:51 by dpowdere          #+#    #+#             */
/*   Updated: 2020/11/07 12:36:04 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*start;
	char			*end;
	char			*trimmed;

	start = (char *)s1;
	while (*start && ft_strchr(set, *start))
		++start;
	end = start;
	while (*end && *(end + 1))
		++end;
	while (end > start && ft_strchr(set, *end))
		--end;
	trimmed = (char *)malloc((end - start + 1) * sizeof(char));
	if (!trimmed)
		return (NULL);
	*(trimmed + (start - ++end)) = '\0';
	while (--end >= start)
		*(trimmed + (start - end)) = *end;
	return (trimmed);
}
