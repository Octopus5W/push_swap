#include "push_swap.h"

int	check_list(t_variable *var)
{
	var->i = 0;
	var->j = 0;
	while (var->i < var->size_a - 1)
	{
		if (var->list_a[var->i] > var->list_a[var->i + 1])
			return (0);
		var->i++;
	}
	while (var->j < var->size_b - 1)
	{
		if (var->list_b[var->j] < var->list_b[var->j + 1])
			return (0);
		var->j++;
	}
	var->i = 0;
	var->j = 0;
	return(1);
}

int count_mouve(t_variable var)
{
	var->count = 0;
	while (var->i != 0 && var->j != 0)
	{
		if (var->i != 0 && var->j != 0)
		{
			var->i--;
			var->j--;
		}
		else if (var->i != 0)
			var->i--;
		else
			var->j--;
		var->count++;
	}
	return (count);
}
int count_mouve_rev(t_variable var)
{
	var->count = 0;
	while (var->i != 0 && var->j != 0)
	{
		if (var->i != 0 && var->j != 0)
		{
			var->i++;
			var->j++;
		}
		else if (var->i != 0)
			var->i++;
		else
			var->j++;
		if (var->i == var->size_a)
			var->i = 0;
		if (var->j == var->size_b)
			var->j = 0;
		var->count++;
	}
	return (count);
}

void select_mouve(t_variable *var)
{
	var->rev = 0;
	var->j = 0;
	var->i = 0;
	var->min_mouve[0] = 5000;
	while (var->i < var->size_a)
	{
		var->j = 0;
		while (var->j < var->size_b)
		{
			var->count = count_mouve(*var);
			var->rev = 0;
			if (var->count > count_mouve_rev(*var))
			{
				var->count = count_mouve_rev(*var);
				var->rev = 1;
			}
			if (var->count < var->min_mouve[0] && var->list_a[var->i] > var->list_b[var->j] && 
				((var->j == 0 && var->list_a[var->i] < var->list_b[var->size_b - 1]) || 
				(var->j > 0 && var->list_a[var->i] < var->list_b[var->j - 1])))
			{
				var->min_mouve[0] = var->count;
				var->min_mouve[1] = var->i;
				var->min_mouve[2] = var->j;
				var->min_mouve[3] = var->rev;
			}
			var->j++;
		}
		var->i++;
	}
}

void algo(t_variable *var)
{
	var->max = get_int_max(var->list_a);
	var->min = get_int_min(var->list_a);
	var->median = get_int_median(var->list_a);
	while (!check_list(t_variable))
	{
		if (var->size_b == 0 || var->list_a[0] < var->var->liste_b[0])
			pb(var);
		else if (var->list_a[0] >)
	}
}

// void algo(t_variable *var)
// {
// 	while (var->count_nb > 2 && var->size_a > 2 && (var->count_nb / 3) < var->size_a)
// 	{
// 			if (var->size_a >= 3 && var->list_a[1] < var->list_a[var->size_a - 1] && var->list_a[1] < var->list_a[0])
// 			{
// 				ra(var);
// 				ft_printf("ra\n");
// 			}
// 			else if (var->size_a >= 3 && var->list_a[1] > var->list_a[var->size_a - 1] && var->list_a[var->size_a - 1] < var->list_a[0])
// 			{
// 				rra(var);
// 				ft_printf("rra\n");
// 			}
// 			else if (var->size_a == 2 && var->list_a[0] > var->list_a[1])
// 			{
// 				sa(var);
// 				ft_printf("sa\n");
// 			}
// 			else
// 			{
// 				pb(var);
// 				ft_printf("pb\n");
// 			}
// 			var->count_mouv++;
// 	}
// }
