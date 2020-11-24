/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 07:52:42 by dpowdere          #+#    #+#             */
/*   Updated: 2020/11/24 21:10:57 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** `ft_calloc` returns NULL if either `nmemb` or `size` is zero.
*/
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	extern int	errno;
	size_t		total_size;
	void		*mem;

	if (nmemb == 0 || size == 0)
		return (NULL);
	total_size = nmemb * size;
	if (~(size_t)0 / size < nmemb)
	{
		errno = ENOMEM;
		return (NULL);
	}
	mem = malloc(total_size);
	if (mem)
		ft_bzero(mem, total_size);
	return (mem);
}
