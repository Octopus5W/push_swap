#include "../include/push_swap.h"

int	check_av(int ac, char *av[], t_variable *var)
{
	if (ac > 2)
	{
		if (tab_is_integer(av + 1) && !tab_is_duplicate(av + 1))
			return (1);
		return (0);
	}
	else if (ac == 2)
	{
		ft_printf("\nbefore var adress %p\n", var);
		ft_printf("\nbefore adress %p\n", var->split);
		var->split = ft_split(av[1]);
		ft_printf("\nafter adress %p\n", var->split);
		if (!var->split)
			return (0);
		if (tab_is_integer(var->split) && !tab_is_duplicate(var->split))
			return (ft_free(var), 1);
		return (ft_free(var), 0);
	}
	else
		return (0);
}
