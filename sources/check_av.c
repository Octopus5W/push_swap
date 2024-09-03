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
		var->split = ft_split(av[1]);
		if (!var->split)
			return (0);
		else if (tab_is_integer(var->split) && !tab_is_duplicate(var->split))
			return (ft_free(var), 1);
		else
			return (ft_free(var), 0);
	}
	else
		return (0);
}
