#include "../include/push_swap.h"

int *cp_list(int *dst, int *src, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		dst[j] = src[j];
		j++;
	}
	return (dst);
}