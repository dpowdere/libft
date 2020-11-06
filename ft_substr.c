/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:56:50 by dpowdere          #+#    #+#             */
/*   Updated: 2020/11/06 13:45:04 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substring;
	size_t			substring_bufsize;

	substring_bufsize = ft_strlen(s) - start;
	if (substring_bufsize > len)
		substring_bufsize = len;
	substring_bufsize += 1;
	substring_bufsize *= sizeof(char);
	substring = (char *)malloc(substring_bufsize);
	if (!substring)
		return (NULL);
	i = start;
	while (i - start < len && s[i])
	{
		substring[i - start] = s[i];
		++i;
	}
	substring[i - start] = '\0';
	return (substring);
}
