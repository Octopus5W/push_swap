#include "../include/push_swap.h"


void	set_list(t_variable var, int count_nb, char *nb[])
{
	var.i = 0;
	var.count_mouv = 0;
	var.count_nb = count_nb - 1;
	var.count_a = count_nb - 1;
	var.count_b = 0;
	while (var.i < var.count_nb)
	{
		var.list_a[var.i] = ft_atoi(nb[var.i]);
		var.i++;
	}
}

int main (int ac, char *av[])
{
	t_variable var; 

	if (check_av(ac, av))
		return (0);
	set_list(var, ac, av);
	
}