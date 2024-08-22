#include "../include/push_swap.h"

int	check_av(int ac, char *av[])
{
	char **tab;
	int i;

	if (ac > 2)
	{
		if (tab_is_integer(av + 1) && !tab_is_duplicate(av + 1))
			return (1);
		return (0);
	}
	else if (ac == 2)
	{
		tab = ft_split(av[1]);
		if (!tab)
			return (1);
		i = 0;
		while (tab[i])
			i++;
		if (tab_is_integer(tab) && !tab_is_duplicate(tab))
			return (ft_free(i, tab), 1);
		return (ft_free(i, tab), 0);
	}
	else
		return (0);
}
