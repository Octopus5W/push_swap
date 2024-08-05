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

void	ft_free(int size, char **tab)
{
		while (--size >= 0)
		{
			free(tab[size]);
			tab[size] = NULL;
		}
		free (tab);
		tab = NULL;
}