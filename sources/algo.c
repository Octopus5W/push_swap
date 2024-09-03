/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:05:20 by hdelbecq          #+#    #+#             */
/*   Updated: 2024/09/03 12:05:21 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move(t_variable *var)
{
	while (var->next_move[1] == -1 && var->next_move[3] == -1
		&& var->next_move[0] > 0 && var->next_move[2] > 0)
		ft_printf("%s", rr(var));
	while (var->next_move[1] == 1 && var->next_move[3] == 1
		&& var->next_move[0] > 0 && var->next_move[2] > 0)
		ft_printf("%s", rrr(var));
	while (var->next_move[1] == 1 && var->next_move[0] > 0)
		ft_printf("%s", rra(var));
	while (var->next_move[3] == 1 && var->next_move[2] > 0)
		ft_printf("%s", rrb(var));
	while (var->next_move[1] == -1 && var->next_move[0] > 0)
		ft_printf("%s", ra(var));
	while (var->next_move[3] == -1 && var->next_move[2] > 0)
		ft_printf("%s", rb(var));
}

void	sort_three_asc(t_variable *var)
{
	var->min = get_int_min(var->list_a, 3);
	var->max = get_int_max(var->list_a, 3);
	if (var->max == var->list_a[0] && var->min == var->list_a[1])
		ft_printf("%s", ra(var));
	else if (var->max == var->list_a[0] && var->min == var->list_a[2])
	{
		ft_printf("%s", ra(var));
		ft_printf("%s", sa(var));
	}
	else if (var->max == var->list_a[1] && var->min == var->list_a[0])
	{
		ft_printf("%s", rra(var));
		ft_printf("%s", sa(var));
	}
	else if (var->max == var->list_a[2] && var->min == var->list_a[1])
		ft_printf("%s", sa(var));
}

void	worth_rotate_a(t_variable *var, int start)
{
	var->i = -1;
	while (var->list_a[++var->i] != start)
		;
	if (var->i < var->size_a)
	{
		while (var->i-- > 0)
			ft_printf("%s", ra(var));
	}
	else
	{
		while (var->i++ < var->size_a)
			ft_printf("%s", rra(var));
	}
}

void	algo(t_variable *var)
{
	if (var->size_a > 2)
	{
		ft_printf("%s", pb(var));
		ft_printf("%s", pb(var));
		while (var->size_a > 3)
		{
			var->next_move[4] = 5000;
			var->i = -1;
			while (++var->i < var->size_a)
			{
				var->j = -1;
				while (++var->j < var->size_b)
				{
					check_worth_move(var->count_move, var->i, var->j,
						var->size_a, var->size_b);
					if (closest_int_down(var->list_a[var->i], var->list_b,
							var->size_b) == var->list_b[var->j]
						&& var->count_move[4] < var->next_move[4])
						cp_list(var->next_move, var->count_move, 5);
				}
			}
			move(var);
			ft_printf("%s", pb(var));
		}
		sort_three_asc(var);
		while (var->size_b > 0)
		{
			var->next_move[4] = 5000;
			var->i = -1;
			while (++var->i < var->size_a)
			{
				var->j = -1;
				while (++var->j < var->size_b)
				{
					check_worth_move(var->count_move, var->i, var->j,
						var->size_a, var->size_b);
					if (closest_int_up(var->list_b[var->j], var->list_a,
							var->size_a) == var->list_a[var->i]
						&& var->count_move[4] < var->next_move[4])
						cp_list(var->next_move, var->count_move, 5);
				}
			}
			move(var);
			ft_printf("%s", pa(var));
		}
	}
	worth_rotate_a(var, get_int_min(var->list_a, var->size_a));
}
