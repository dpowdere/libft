/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 09:04:55 by dpowdere          #+#    #+#             */
/*   Updated: 2020/11/12 02:01:21 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n
			&& ((unsigned char *)s1)[i] != '\0'
			&& ((unsigned char *)s2)[i] != '\0'
			&& ((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
		++i;
	if (i == n)
		--i;
	return ((int)((unsigned char *)s1)[i] - (((unsigned char *)s2)[i]));
}
