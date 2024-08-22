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

int	closest_int_down(int nb, int *list, int size)
{
	int i;
	int closest_down;

	closest_down = get_int_max(list, size);
		i = -1;
	while (++i < size)
	{
		if ((list[i] < nb && list[i] > closest_down) || (list[i] < nb && closest_down > nb))
			closest_down = list[i];
	}
	return (closest_down);
}
int	closest_int_up(int nb, int *list, int size)
{
	int i;
	int closest_up;

	closest_up = get_int_min(list, size);
	i = -1;
	while (++i < size)
	{
		if ((list[i] > nb && list[i] < closest_up) || (list[i] > nb && closest_up < nb))
			closest_up = list[i];
	}
	return(closest_up);
}