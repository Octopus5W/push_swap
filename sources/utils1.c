/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:06:18 by hdelbecq          #+#    #+#             */
/*   Updated: 2024/09/03 14:32:32 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	count_move_down(int i)
{
	int	count;

	count = 0;
	while (i != 0)
	{
		i--;
		count++;
	}
	return (count);
}

int	count_move_up(int i, int max_i)
{
	int	count;

	count = 0;
	while (i != max_i)
	{
		i++;
		count++;
	}
	return (count);
}

int	is_asc(int list[], int size)
{
	int	i;

	i = -1;
	while (++i < size - 1)
	{
		if (list[i] > list[i + 1])
			return (0);
	}
	return (1);
}

void	set_count_move(t_variable *var, int count[4])
{
	if (count[0] < count[1])
	{
		var->count_move[1] = -1;
		var->count_move[4] = count[0];
	}
	else
	{
		var->count_move[1] = 1;
		var->count_move[4] = count[1];
	}
	if (count[2] < count[3])
	{
		var->count_move[3] = -1;
		var->count_move[4] += count[2];
	}
	else
	{
		var->count_move[3] = 1;
		var->count_move[4] += count[3];
	}
}

int	*check_worth_move(t_variable *var)
{
	int	count[4];

	count[0] = count_move_down(var->i);
	count[1] = count_move_up(var->i, var->size_a);
	count[2] = count_move_down(var->j);
	count[3] = count_move_up(var->j, var->size_b);
	var->count_move[0] = var->i;
	var->count_move[2] = var->j;
	set_count_move(var, count);
	if (var->count_move[1] == -1 && var->count_move[1] == var->count_move[3])
	{
		if (count[0] < count[2])
			var->count_move[4] = count[2];
		else
			var->count_move[4] = count[0];
	}
	else if (var->count_move[1] == 1
		&& var->count_move[1] == var->count_move[3])
	{
		if (count[1] < count[3])
			var->count_move[4] = count[3];
		else
			var->count_move[4] = count[1];
	}
	return (var->count_move);
}
