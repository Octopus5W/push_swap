/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:06:22 by hdelbecq          #+#    #+#             */
/*   Updated: 2024/09/03 12:51:45 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_int_max(int list[], int len)
{
	int	max;

	max = list[--len];
	while (--len >= 0)
	{
		if (max < list[len])
			max = list[len];
	}
	return (max);
}

int	get_int_min(int list[], int len)
{
	int	min;

	min = list[--len];
	while (--len >= 0)
	{
		if (min > list[len])
			min = list[len];
	}
	return (min);
}

int	closest_int_down(int nb, int list[], int size)
{
	int	i;
	int	closest_down;

	closest_down = get_int_min(list, size);
	if (closest_down > nb)
		return (get_int_max(list, size));
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
	int	i;
	int	closest_up;

	closest_up = get_int_max(list, size);
	if (closest_up < nb)
		return (get_int_min(list, size));
	i = -1;
	while (++i < size)
	{
		if (list[i] > nb && list[i] < closest_up)
			closest_up = list[i];
	}
	return (closest_up);
}

int	*cp_list(int *dst, int *src, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		dst[j] = src[j];
		j++;
	}
	return (dst);
}
