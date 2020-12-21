#include <stdio.h>
#include <string.h>

#include "libft.h"

int main()
{
	char s[100];
	char sep[10] = " \n\t";
	char *s2;

	(void)strcpy(s, " \t\n0123   \n");
	s2 = NULL;
	printf("trim: [%s], trimmed: [%s]\n", s, (s2 = ft_strtrim(s, sep)));
	printf("bytesize: %lu\n\n", strlen(s2));
	free(s2);

	(void)strcpy(s, " \t\n   \n");
	s2 = NULL;
	printf("trim: [%s], trimmed: [%s]\n", s, (s2 = ft_strtrim(s, sep)));
	printf("bytesize: %lu\n\n", strlen(s2));
	free(s2);

	s[0] = '\0';
	s2 = NULL;
	printf("trim: [%s], trimmed: [%s]\n", s, (s2 = ft_strtrim(s, sep)));
	printf("bytesize: %lu\n\n", strlen(s2));
	free(s2);

	(void)strcpy(s, " \t   0123456789");
	s2 = NULL;
	printf("trim: [%s], trimmed: [%s]\n", s, (s2 = ft_strtrim(s, sep)));
	printf("bytesize: %lu\n\n", strlen(s2));
	free(s2);

	return 0;
}
