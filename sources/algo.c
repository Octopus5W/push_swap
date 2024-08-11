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

void algo(t_variable *var)
{
	while (var->count_nb > 2 && var->size_a > 2 && (var->count_nb / 3) < var->size_a)
	{
			if (var->size_a >= 3 && var->list_a[1] < var->list_a[var->size_a - 1] && var->list_a[1] < var->list_a[0])
			{
				ra(var);
				ft_printf("ra\n");
			}
			else if (var->size_a >= 3 && var->list_a[1] > var->list_a[var->size_a - 1] && var->list_a[var->size_a - 1] < var->list_a[0])
			{
				rra(var);
				ft_printf("rra\n");
			}
			else if (var->size_a == 2 && var->list_a[0] > var->list_a[1])
			{
				sa(var);
				ft_printf("sa\n");
			}
			else
			{
				pb(var);
				ft_printf("pb\n");
			}
			var->count_mouv++;
	}
 	// while (!check_list(var))
	// {
	// 	while (var->size_a > 0)
	// 	{
	// 		if (var->size_a >= 3 && var->list_a[1] < var->list_a[var->size_a - 1] && var->list_a[1] < var->list_a[0])
	// 		{
	// 			ra(var);
	// 			ft_printf("ra\n");
	// 		}
	// 		else if (var->size_a >= 3 && var->list_a[1] > var->list_a[var->size_a - 1] && var->list_a[var->size_a - 1] < var->list_a[0])
	// 		{
	// 			rra(var);
	// 			ft_printf("rra\n");
	// 		}
	// 		else if (var->size_a == 2 && var->list_a[0] > var->list_a[1])
	// 		{
	// 			sa(var);
	// 			ft_printf("sa\n");
	// 		}
	// 		else
	// 		{
	// 			pb(var);
	// 			ft_printf("pb\n");
	// 		}
	// 		var->count_mouv++;
	// 	}
	// 	while (var->size_b > 0)
	// 	{
	// 		if (var->size_b >= 3 && var->list_b[1] > var->list_b[var->size_b - 1] && var->list_b[1] > var->list_b[0])
	// 		{
	// 			rb(var);
	// 			ft_printf("rb\n");
	// 		}
	// 		else if (var->size_b >= 3 && var->list_b[1] < var->list_b[var->size_b - 1] && var->list_b[var->size_b - 1] > var->list_b[0])
	// 		{
	// 			rrb(var);
	// 			ft_printf("rrb\n");
	// 		}
	// 		else if (var->size_b == 2 && var->list_b[0] < var->list_b[1])
	// 		{
	// 			sb(var);
	// 			ft_printf("sb\n");
	// 		}
	// 		else
	// 		{
	// 			pa(var);
	// 			ft_printf("pa\n");
	// 		}
	// 		var->count_mouv++;
	// 	}
	// }
}


// works but to long
 	// while (!check_list(var))
	// {
	// 	while (var->size_a > 0)
	// 	{
	// 		if (var->size_a >= 3 && var->list_a[1] < var->list_a[var->size_a - 1] && var->list_a[1] < var->list_a[0])
	// 		{
	// 			ra(var);
	// 			ft_printf("ra\n");
	// 		}
	// 		else if (var->size_a >= 3 && var->list_a[1] > var->list_a[var->size_a - 1] && var->list_a[var->size_a - 1] < var->list_a[0])
	// 		{
	// 			rra(var);
	// 			ft_printf("rra\n");
	// 		}
	// 		else if (var->size_a == 2 && var->list_a[0] > var->list_a[1])
	// 		{
	// 			sa(var);
	// 			ft_printf("sa\n");
	// 		}
	// 		else
	// 		{
	// 			pb(var);
	// 			ft_printf("pb\n");
	// 		}
	// 		var->count_mouv++;
	// 	}
	// 	while (var->size_b > 0)
	// 	{
	// 		if (var->size_b >= 3 && var->list_b[1] > var->list_b[var->size_b - 1] && var->list_b[1] > var->list_b[0])
	// 		{
	// 			rb(var);
	// 			ft_printf("rb\n");
	// 		}
	// 		else if (var->size_b >= 3 && var->list_b[1] < var->list_b[var->size_b - 1] && var->list_b[var->size_b - 1] > var->list_b[0])
	// 		{
	// 			rrb(var);
	// 			ft_printf("rrb\n");
	// 		}
	// 		else if (var->size_b == 2 && var->list_b[0] < var->list_b[1])
	// 		{
	// 			sb(var);
	// 			ft_printf("sb\n");
	// 		}
	// 		else
	// 		{
	// 			pa(var);
	// 			ft_printf("pa\n");
	// 		}
	// 		var->count_mouv++;
	// 	}
	// }