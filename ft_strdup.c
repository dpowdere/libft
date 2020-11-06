/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:17:34 by dpowdere          #+#    #+#             */
/*   Updated: 2020/11/06 12:41:21 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stddef.h>
#include <stdlib.h>

#include "libft.h"

char	*ft_strdup(const char *s)
{
	extern int	errno;
	char		*dup;
	size_t		bufsize;

	bufsize = (ft_strlen(s) + 1) * sizeof(char);
	dup = (char *)malloc(bufsize);
	if (!dup)
	{
		errno = ENOMEM;
		return (NULL);
	}
	(void)ft_strlcpy(dup, s, bufsize);
	return (dup);
}
