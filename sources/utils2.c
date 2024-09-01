#include "../include/push_swap.h"

int get_int_max(int list[], int len)
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
int get_int_min(int list[], int len)
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

int get_int_median(int list[], int len)
{
	int median;
	int i;

	median = -2147483648;
	i = -1;
	while (++i < (len / 2) + 1)
		median = closest_int_up(median, list, len);
	return (median);
}

int	closest_int_down(int nb, int list[], int size)
{
	int i;
	int closest_down;

	closest_down = get_int_min(list, size);
	if (closest_down > nb)
		return(get_int_max(list, size));
	i = -1;
	while (++i < size)
	{
		if (list[i] < nb && list[i] > closest_down)
			closest_down = list[i];
	}
	return (closest_down);
}
int	closest_int_up(int nb, int list[], int size)
{
	int i;
	int closest_up;

	closest_up = get_int_max(list, size);
	if (closest_up < nb)
		return(get_int_min(list, size));
	i = -1;
	while (++i < size)
	{
		if (list[i] > nb && list[i] < closest_up)
			closest_up = list[i];
	}
	return(closest_up);
}