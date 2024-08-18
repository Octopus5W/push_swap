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

int count_move(t_variable var)
{
	var.count = 0;
	while (var.i != 0 || var.j != 0)
	{
		if (var.i != 0 && var.j != 0)
		{
			var.i--;
			var.j--;
		}
		else if (var.i != 0)
			var.i--;
		else
			var.j--;
		var.count++;
	}
	return (var.count);
}
int count_move_rev(t_variable var)
{
	var.count = 0;
	while (var.i != 0 || var.j != 0)
	{
		if (var.i != 0 && var.j != 0)
		{
			var.i++;
			var.j++;
		}
		else if (var.i != 0)
			var.i++;
		else
			var.j++;
		if (var.i == var.size_a)
			var.i = 0;
		if (var.j == var.size_b)
			var.j = 0;
		var.count++;
	}
	return (var.count);
}

void select_move(t_variable *var)
{
	var->rev = 0;
	var->j = 0;
	var->i = 0;
	var->next_move[0] = 5000;
	var->min = get_int_min(var->list_b, var->size_b);
	var->max = get_int_max(var->list_b, var->size_b);
	while (var->i < var->size_a)
	{
		var->j = 0;
		while (var->j < var->size_b)
		{
			// set before after
			if (var->j == var->size_b - 1)
			{
				var->before = var->j - 1;
				var->after = 0;
			}
			else if (var->j == 0)
			{
				var->before = var->size_b - 1;
				var->after = var->j + 1;
			}
			else
			{
				var->before = var->j - 1;
				var->after = var->j + 1;
			}
			//
			//condition for next move
			if ((var->list_a[var->i] < var->min && var->list_b[var->j] == var->max) ||
				(var->list_a[var->i] > var->max && var->list_b[var->j] == var->min) ||
				(var->list_a[var->i] < var->max && var->list_a[var->i] > var->min && 
				var->list_b[var->before] > var->list_a[var->i] && var->list_b[var->j] < var->list_a[var->i]))
			{
				var->count = count_move(*var);
				var->rev = 0;
				if (var->count > count_move_rev(*var))
				{
					var->count = count_move_rev(*var);
					var->rev = 1;
				}
				if (var->count < var->next_move[0])
				{
					// set next_move
					var->next_move[0] = var->count;
					var->next_move[1] = var->i;
					var->next_move[2] = var->j;
					var->next_move[3] = var->rev;
				}
			}
			var->j++;
		}
		var->i++;
	}
}

void algo(t_variable *var)
{
	while (!check_list(var))
	{
		if (var->size_a > 0 && var->size_b < 2)
			pb(var);
		else
			{
				select_move(var);
				if (var->size_a == 0)
					break;
				while (var->next_move[0] > 0 && var->next_move[3])
				{
					if (var->next_move[1] > 0 && var->next_move[2] > 0)
						rrr(var);
					else if (var->next_move[1] > 0)
						rra(var);
					else if (var->next_move[2] > 0)
						rrb(var);		
				}
				while (var->next_move[0] > 0 && !var->next_move[3])
				{
					if (var->next_move[1] > 0 && var->next_move[2] > 0)
						rr(var);
					else if (var->next_move[1] > 0)
						ra(var);
					else if (var->next_move[2] > 0)
						rb(var);
				}
				if (var->size_a > 0 && var->next_move[0] == 0)
					pb(var);
			}
	}
	// while (var->size_b)
	// 	pa(var);
	// while (var->min != var->list_a[0])
	// 	ra(var);
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
