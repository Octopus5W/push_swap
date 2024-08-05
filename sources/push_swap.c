#include "../include/push_swap.h"

void print_lists(t_variable var)
{
	var.i = 0;
	var.j = 0;
	// int i = -1;
	// var.size_a = 100;
	// var.size_b = 100;
	// while (++i < var.size_a)
	// 	var.list_a[i] = i + 165 * i;
	// i = -1;
	// while (++i < var.size_b)
	// 	var.list_b[i] = i;

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

void	set_list(t_variable *var, int count_nb, char *nb[])
{
	var->i = 0;
	var->count_mouv = 0;
	var->count_nb = count_nb;
	var->size_a = count_nb;
	var->size_b = 0;
	while (var->i < var->count_nb)
	{
		var->list_a[var->i] = ft_atoi(nb[var->i]);
		// ft_printf("%i\t %i\n", var->list_a[var->i], ft_atoi(nb[var->i]));
		var->i++;
	}
}

int main (int ac, char *av[])
{
	t_variable var; 

	if (check_av(ac, av))
		return (0);
	// ne fonctionne pas avec 2 argument : faire le split
	if (ac > 2)
		set_list(&var, ac - 1, av + 1);
	else if (ac == 2)
	{
		var.i = 0;
		var.split = ft_split2(av[1]);
		ft_printf("ok\n");
		if (!var.split || !*var.split)
			ft_printf("error : format argument");
		while (var.split && var.split[var.i])
			ft_printf("%s\n", var.split[var.i++]);
		ft_free(3, var.split);

	}
	else
		ft_printf ("error : count argument");
	return (0);
}