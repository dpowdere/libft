/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:41:28 by dpowdere          #+#    #+#             */
/*   Updated: 2020/11/07 13:16:51 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#define IN_WORD		1
#define OUT_WORD	0

static void	ft___count(char const *s, char c, size_t *n_words, size_t *n_chars)
{
	char	*cursor;
	int		state;

	*n_words = (size_t)0;
	*n_chars = (size_t)0;
	cursor = (char *)s;
	state = OUT_WORD;
	while (s != NULL && *cursor)
	{
		if (*cursor == c && state == IN_WORD)
			state = OUT_WORD;
		else if (*cursor != c && state == IN_WORD)
			++*n_chars;
		else if (*cursor != c && state == OUT_WORD)
		{
			state = IN_WORD;
			++*n_words;
		}
		++cursor;
	}
}

static void	ft___fill(char const *s, char c, char **mem, size_t n_words)
{
	char	*read_cursor;
	char	*write_cursor;
	int		state;

	*(mem + n_words) = NULL;
	write_cursor = (char *)(mem + n_words + 1);
	read_cursor = (char *)s;
	state = OUT_WORD;
	while (s != NULL && *read_cursor)
	{
		if (*read_cursor == c && state == IN_WORD)
		{
			state = OUT_WORD;
			*write_cursor++ = '\0';
		}
		else if (*read_cursor != c && state == IN_WORD)
			*write_cursor++ = *read_cursor;
		else if (*read_cursor != c && state == OUT_WORD)
		{
			state = IN_WORD;
			*write_cursor = *read_cursor;
			*mem++ = write_cursor++;
		}
		++read_cursor;
	}
}

char		**ft_split(char const *s, char c)
{
	size_t	n_words;
	size_t	n_chars;
	char	**string_array;

	n_words = (size_t)0;
	n_chars = (size_t)0;
	ft___count(s, c, &n_words, &n_chars);
	string_array = (char **)malloc(
			(n_words + 1) * sizeof(char *) +
			(n_chars + n_words) * sizeof(char));
	if (!string_array)
		return (NULL);
	ft___fill(s, c, string_array, n_words);
	return (string_array);
}
