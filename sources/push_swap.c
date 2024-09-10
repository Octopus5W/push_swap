/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:05:52 by hdelbecq          #+#    #+#             */
/*   Updated: 2024/09/10 15:00:11 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_lists(t_variable var)
{
	var.i = 0;
	var.j = 0;
	ft_printf("list_a\t\tlist_b\n");
	while (var.i < var.size_a || var.j < var.size_b)
	{
		if (var.i < var.size_a)
		{
			ft_printf("%i\t\t", var.list_a[var.i]);
			var.i++;
		}
		else
			ft_printf("\t\t");
		if (var.j < var.size_b)
		{
			ft_printf("%i\n", var.list_b[var.j]);
			var.j++;
		}
		else
			ft_printf("\n");
	}
	ft_printf("_________________________________________\n\n");
}

void	set_list(t_variable *var, char *nb[])
{
	var->i = 0;
	var->j = 0;
	while (nb[var->j])
		var->j++;
	var->size_a = var->j;
	var->size_b = 0;
	while (var->i < var->j)
	{
		var->list_a[var->i] = ft_atoi(nb[var->i]);
		var->i++;
	}
	var->i = 0;
	var->j = 0;
}

int	main(int ac, char *av[])
{
	t_variable	var;

	if (!check_av(ac, av, &var))
		return (0);
	if (ac > 2 && ac <= 501)
		set_list(&var, av + 1);
	else if (ac == 2)
	{
		var.split = ft_split(av[1]);
		if (!var.split)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		set_list(&var, var.split);
		ft_free(&var);
	}
	if (is_asc(var.list_a, var.size_a))
		return (0);
	else if (var.size_a == 2 && var.list_a[0] > var.list_a[1])
		ft_printf("%s", sa(&var));
	else if (var.size_a == 3)
		sort_three_asc(&var);
	algo(&var);
	return (0);
}
