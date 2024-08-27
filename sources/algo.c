#include "push_swap.h"

void algo(t_variable *var)
{	
	var->i = -1;
	var->next_move[4] = 5000;
	if (var->size_a > 2 && var->size_b == 0)
	{
		var->median = get_int_median(var->list_a, var->size_a);
		var->min = closest_int_down(var->median, var->list_a, var->size_a);
		var->max = closest_int_up(var->median, var->list_a, var->size_a);
		while (var->list_a[0] != var->min)
			ft_printf("%s", ra(var));
		ft_printf("%s", pb(var));
		while (var->list_a[0] != var->max)
			ft_printf("%s", ra(var));
		ft_printf("%s", pb(var));
	}
	while (var->size_a > 2)
	{
		while (++var->i < var->size_a)
		{
			var->j = -1;
			while (++var->j < var->size_b)
			{
				//condition for next move // last condition utils ?
				check_worth_move(var->count_move ,var->i, var->j, var->size_a, var->size_b);
				if (closest_int_up(var->list_a[var->i], var->list_b, var->size_b) == var->list_b[var->j]
					&& var->count_move[4] < var->next_move[4] && (var->next_move[5] = -1))
					cp_list(var->next_move, var->count_move, 5);
				else if (((var->j == 0 && closest_int_down(var->list_a[var->i], var->list_b, var->size_b) == var->list_b[var->size_b])
					|| (var->j > 0 && closest_int_down(var->list_a[var->i], var->list_b, var->size_b) == var->list_b[var->j + 1]))
					&& var->count_move[4] + 1 < var->next_move[4] && (var->next_move[5] = 1))
					cp_list(var->next_move, var->count_move, 5);
				
		}
	}
	if (var->list_a[0] > var->list_a[1])
		ft_printf("%s", sa(var));
	}
	if (var->next_move[5] == 1 && (var->next_move[2]++))
			ft_printf("%s", rb(var));
	while (var->next_move[1] == -1 && var->next_move[3] == -1 && var->next_move[0] > 0 && var->next_move[2] > 0)//count down
			ft_printf("%s", rr(var));
	while (var->next_move[1] == 1 && var->next_move[3] == 1 && var->next_move[0] > 0 && var->next_move[2] > 0) // count up
			ft_printf("%s", rrr(var));
	while (var->next_move[1] == 1 && var->next_move[0] > 0) // count up
			ft_printf("%s", rra(var));
	while (var->next_move[3] == 1 && var->next_move[2] > 0) // count up
			ft_printf("%s", rrb(var));		
	while (var->next_move[1] == -1 && var->next_move[0] > 0)//count down
			ft_printf("%s", ra(var));
	while (var->next_move[3] == -1 && var->next_move[2] > 0)//count down
			ft_printf("%s", rb(var));
	ft_printf("%s", pb(var));
}