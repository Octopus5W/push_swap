#include "../include/push_swap.h"

int is_integer(char *s)
{
	int i;
	char *check;

	i = 0;
	if(!s || !*s)
		return (0);
	while ((s[i] >= 7 && s[i] <= 13) || s[i] == 32)
		i++;
	while (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i])
		return (0);
	check = ft_itoa(ft_atoi(s));
	if (!check)
		return (0);
	i = 0;
	while (s[i] == check[i] && check[i] && s[i])
		i++;
	if(!s[i] && !check[i])
		return(free(check), 1);
	return (free(check), 0);
}

int	ft_atoi(char *s)
{
	int	nb;
	int sign;

	nb = 0;
	sign = 1;
	if (!s || !*s)
		return (-1);
	while ((*s >= 7 && *s <= 13) || *s == 32)
		s++;
	while (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		nb = nb * 10 + (*s - 48);
		s++;
	}
	return (nb * sign);
}

int	check_av_isInt(int ac, char *av[])
{
	int i;

	i = -1;
	if (ac <= 1)
		return (1);
	while (++i < ac && is_integer(av[i]));
	if (i == ac)
		return (1);
	ft_printf("Only int are supported\n");
	return (0);
}

int	check_av_duplicate(int ac, char *av[])
{
	int i;
	int j;
	int check;

	i = -1;
	if (ac <= 1)
		return (1);
	while (++i < ac && (j = i + 1))
	{
		check = ft_atoi(av[i]);
		while (j < ac && check != ft_atoi(av[j]))
			j++;
		if (j < ac)
		{
			ft_printf("Duplicate integer not allowed\n");
			return (1);
		}
	}
	return (0);
}
int	check_av(int ac, char *av[])
{
	char **tab;
	int i;

	if (ac > 2)
	{
		if (check_av_isInt(ac - 1, av + 1) && !check_av_duplicate(ac - 1, av + 1))
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
		if (check_av_isInt(i, tab) && !check_av_duplicate(i, tab))
			return (ft_free(i, tab), 1);
		return (ft_free(i, tab), 0);
	}
	else
		return (0);
}
