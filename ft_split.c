/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:41:28 by dpowdere          #+#    #+#             */
/*   Updated: 2020/11/25 12:48:31 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** `ft_split` allocates a single contiguous array of memory blocks and
** populates them both with an array of pointers to splitted C-strings and
** with the strings themselves. So when deallocation is needed, you only have
** to deallocate the whole range at once without hassle of deallocating the
** individual strings.
*/
#include <stddef.h>
#include <stdlib.h>

#define IN_SEGMENT	1
#define OUT_SEGMENT	0

static void	ft___count(char const *s, char c,
					size_t *n_segments, size_t *n_chars)
{
	int		state;

	*n_segments = 0;
	*n_chars = 0;
	state = OUT_SEGMENT;
	while (*s)
	{
		if (*s == c && state == IN_SEGMENT)
			state = OUT_SEGMENT;
		else if (*s != c)
		{
			++*n_chars;
			if (state == OUT_SEGMENT)
			{
				state = IN_SEGMENT;
				++*n_segments;
			}
		}
		++s;
	}
}

static void	ft___fill(char const *s, char c, char **mem, size_t n_segments)
{
	char	*write_cursor;
	int		state;

	*(mem + n_segments) = NULL;
	write_cursor = (char *)(mem + n_segments + 1);
	state = OUT_SEGMENT;
	while (s && *s)
	{
		if (*s == c && state == IN_SEGMENT)
		{
			state = OUT_SEGMENT;
			*write_cursor++ = '\0';
		}
		else if (*s != c && state == IN_SEGMENT)
			*write_cursor++ = *s;
		else if (*s != c && state == OUT_SEGMENT)
		{
			state = IN_SEGMENT;
			*write_cursor = *s;
			*mem++ = write_cursor++;
		}
		++s;
	}
}

char		**ft_split(char const *s, char c)
{
	size_t	n_segments;
	size_t	n_chars;
	char	**string_array;

	n_segments = 0;
	n_chars = 0;
	if (s)
		ft___count(s, c, &n_segments, &n_chars);
	string_array = (char **)malloc(
			(n_segments + 1) * sizeof(char *) +
			(n_chars + n_segments) * sizeof(char));
	if (!string_array)
		return (NULL);
	ft___fill(s, c, string_array, n_segments);
	return (string_array);
}
