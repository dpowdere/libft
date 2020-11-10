/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 22:32:15 by dpowdere          #+#    #+#             */
/*   Updated: 2020/11/06 23:56:47 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stddef.h>
#include <stdlib.h>

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;
	size_t	i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!str)
	{
		errno = ENOMEM;
		return (NULL);
	}
	i = 0;
	while (i < len1 || i < len2)
	{
		if (i < len1)
			str[i] = s1[i];
		if (i < len2)
			str[len1 + i] = s2[i];
		++i;
	}
	return (str);
}