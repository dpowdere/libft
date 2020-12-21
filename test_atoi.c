#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int	ft_atoi(const char *str);

int	main(int argc, char **argv)
{
	int	i;

	printf("INT_MIN: %d\n", INT_MIN);
	printf("INT_MAX: %d\n", INT_MAX);
	if (argc < 2)
		return 0;
	i = 0;
	while (++i < argc)
		printf("string:  %s\natoi:    %d\nft_atoi: %d\n\n",
				argv[i], atoi(argv[i]), ft_atoi(argv[i]));
	return (0);
}
