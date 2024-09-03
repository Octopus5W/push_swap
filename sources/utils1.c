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

int	*check_worth_move(int *next_move, int i, int j, int max_i, int max_j)
{
	int	count[4];

	count[0] = count_move_down(i);
	count[1] = count_move_up(i, max_i);
	count[2] = count_move_down(j);
	count[3] = count_move_up(j, max_j);
	next_move[0] = i;
	next_move[2] = j;
	if (max_j == 0 && count[0] < count[1] && (next_move[1] = -1))
		next_move[4] = count[0];
	else if (max_j == 0 && count[0] > count[1] && (next_move[1] = 1))
		next_move[4] = count[1];
	else if (count[0] < count[1] && count[2] < count[3] && (next_move[1] = -1)
		&& (next_move[3] = -1))
		next_move[4] = count[0];
	else if (count[0] > count[1] && count[2] > count[3] && (next_move[1] = 1)
		&& (next_move[3] = 1))
		next_move[4] = count[1];
	else if (count[0] < count[1] && count[2] > count[3] && (next_move[1] = -1)
		&& (next_move[3] = 1))
		next_move[4] = count[0] + count[3];
	else if (count[0] > count[1] && count[2] < count[3] && (next_move[1] = 1)
		&& (next_move[3] = -1))
		next_move[4] = count[1] + count[2];
	return (next_move);
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

void	ft_free(t_variable *var)
{
	int	i;

	i = 0;
	while (var->split[i])
	{
		free(var->split[i]);
		var->split[i++] = NULL;
	}
	free(var->split);
	var->split = NULL;
}
