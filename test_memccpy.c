#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int main(int argc, char **argv)
{
	char *dst;
	char *src;
	char c;
	int  i;

	if (argc != 5)
	{
		printf("Pass in `dst`, `src`, `c` and `i` as command line arguments\n");
		return 1;
	}
	dst = strdup(argv[1]);
	src = strdup(argv[2]);
	c = argv[3][0];
	i = atoi(argv[4]);
	printf("memccpy (sy): %20p, ", memccpy(dst, src, c, i));
	printf("dst: %s\n", dst);
	dst = strcpy(dst, argv[1]);
	src = strcpy(src, argv[2]);
	printf("memccpy (ft): %20p, ", ft_memccpy(dst, src, c, i));
	printf("dst: %s\n", dst);
	return 0;
}
