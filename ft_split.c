/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:41:28 by dpowdere          #+#    #+#             */
/*   Updated: 2020/11/24 19:02:34 by dpowdere         ###   ########.fr       */
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

#define IN_WORD		1
#define OUT_WORD	0

static void	ft___count(char const *s, char c, size_t *n_words, size_t *n_chars)
{
	int		state;

	*n_words = (size_t)0;
	*n_chars = (size_t)0;
	state = OUT_WORD;
	while (*s)
	{
		if (*s == c && state == IN_WORD)
			state = OUT_WORD;
		else if (*s != c)
		{
			++*n_chars;
			if (state == OUT_WORD)
			{
				state = IN_WORD;
				++*n_words;
			}
		}
		++s;
	}
}

static void	ft___fill(char const *s, char c, char **mem, size_t n_words)
{
	char	*write_cursor;
	int		state;

	*(mem + n_words) = NULL;
	write_cursor = (char *)(mem + n_words + 1);
	state = OUT_WORD;
	while (s && *s)
	{
		if (*s == c && state == IN_WORD)
		{
			state = OUT_WORD;
			*write_cursor++ = '\0';
		}
		else if (*s != c && state == IN_WORD)
			*write_cursor++ = *s;
		else if (*s != c && state == OUT_WORD)
		{
			state = IN_WORD;
			*write_cursor = *s;
			*mem++ = write_cursor++;
		}
		++s;
	}
}

char		**ft_split(char const *s, char c)
{
	size_t	n_words;
	size_t	n_chars;
	char	**string_array;

	n_words = (size_t)0;
	n_chars = (size_t)0;
	if (s)
		ft___count(s, c, &n_words, &n_chars);
	string_array = (char **)malloc(
			(n_words + 1) * sizeof(char *) +
			(n_chars + n_words) * sizeof(char));
	if (!string_array)
		return (NULL);
	ft___fill(s, c, string_array, n_words);
	return (string_array);
}
