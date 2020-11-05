/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 07:52:42 by dpowdere          #+#    #+#             */
/*   Updated: 2020/11/05 09:49:16 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	extern int	errno;
	size_t		total_size;
	void		*mem;

	if (nmemb == (size_t)0 || size == (size_t)0)
		return (NULL);
	total_size = nmemb * size;
	if (SIZE_MAX / size < nmemb)
	{
		errno = ENOMEM;
		return (NULL);
	}
	mem = malloc(total_size);
	if (mem)
		ft_bzero(mem, total_size);
	return (mem);
}
