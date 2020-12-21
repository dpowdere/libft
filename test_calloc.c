#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int main()
{
	long double	*pd;
	char		*pc;

	pd = (long double *)calloc(0, 0);
	printf("address: %p, pointer size: %lu, "
			"allocated memory size: %lu, mem value: %Lg\n",
			pd, sizeof(pd), sizeof(*pd), (*pd = 3.4));
	free(pd);

	pc = (char *)calloc(0, 0);
	printf("address: %p, pointer size: %lu, "
			"allocated memory size: %lu, mem value: %d\n",
			pc, sizeof(pc), sizeof(*pc), (*pc = 127));
	free(pc);

	pd = (long double *)malloc(0);
	printf("address: %p, pointer size: %lu, "
			"allocated memory size: %lu, mem value: %Lg\n",
			pd, sizeof(pd), sizeof(*pd), (*pd = 3.4));
	free(pd);

	pc = (char *)malloc(0);
	printf("address: %p, pointer size: %lu, "
			"allocated memory size: %lu, mem value: %d\n",
			pc, sizeof(pc), sizeof(*pc), (*pc = 127));
	free(pc);

	printf("\nft_calloc\n\n");

	pd = (long double *)ft_calloc(0, 0);
	printf("address: %p, pointer size: %lu, "
			"allocated memory size: %lu, mem value: %Lg\n",
			pd, sizeof(pd), sizeof(*pd), (*pd = 3.4));
	free(pd);

	pc = (char *)ft_calloc(0, 0);
	printf("address: %p, pointer size: %lu, "
			"allocated memory size: %lu, mem value: %d\n",
			pc, sizeof(pc), sizeof(*pc), (*pc = 127));
	free(pc);


	return (0);
}
