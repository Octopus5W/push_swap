#include "../include/push_swap.h"

int get_int_max(int *list, int len)
{
	int max;

	max = list[--len];
	while (--len >= 0)
	{
		if (max < list[len])
				max = list[len];
	}
	return (max);
}
int get_int_min(int *list, int len)
{
	int min;

	min = list[--len];
	while (--len >= 0)
	{
		if (min > list[len])
				min = list[len];
	}
	return (min);
}

int get_int_median(int *list, int len)
{
	int median;
	int t_int;
	int i;
	int j;

	median = get_int_min(list, len);
	i = 0;
	while (++i < len/2)
	{
		j = -1;
		t_int = list[0];
		while (++j < len)
		{
			if (list[j] < t_int && t_int > median)
				t_int = list[j];
		}
		median = t_int;
	}
	return (median);
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