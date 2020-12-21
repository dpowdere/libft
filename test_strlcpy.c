#include <stdio.h>
#include <string.h>
#include "libft.h"

int main()
{
	char s[20] = "12345";

	printf("%lu\n", strlcpy(s, "abc", 10));
	printf("%lu\n", ft_strlcpy(s, NULL, 10));
	printf("%lu\n", ft_strlcpy(NULL, "", 10));
	printf("%lu\n", ft_strlcpy(NULL, NULL, 10));
	return 0;
}
