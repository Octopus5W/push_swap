#include "../include/push_swap.h"

int count_move_down(int i, int j)
{
	int count;

	count = 0;
	while (i != 0 || j != 0)
	{
		if (i != 0 && j != 0)
		{
			i--;
			j--;
		}
		else if (i != 0)
			i--;
		else if (j != 0)
			j--;
		count++;
	}
	return (count);
}
int count_move_up(int i, int j, int range_i, int range_j)
{
	int count;

	count = 0;
	while (i != 0 || j != 0)
	{
		if (i != 0 && j != 0)
		{
			i++;
			j++;
		}
		else if (i != 0)
			i++;
		else if (j != 0)
			j++;
		if (i == range_i)
			i = 0;
		if (j == range_j)
			j = 0;
		count++;
	}
	return (count);
}

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