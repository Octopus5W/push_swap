#include "../include/push_swap.h"

int is_integer(char *s)
{
	if(!s || !*s)
		return (0);
	while ((*s >= 7 && *s <= 13) || *s == 32)
		s++;
	while (*s == '+' || *s == '-')
		s++;
	while (s && *s >= '0' && *s <= '9')
		s++;
	if (!*s)
		return (1);
	else
		return (0);
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

	i = 0;
	if (ac <= 1)
		return (1);
	while (++i < ac && is_integer(av[i]));
	if (i != ac)
		return (1);
	return (0);
}

int	check_av_double(int ac, char *av[])
{
	int i;
	int j;

	i = 0;
	if (ac <= 1)
		return (1);
	while (++i < ac && (j = i))
		while (++j < ac && ft_atoi(av[i]) != ft_atoi(av[j]));
	if (i != ac)
		return (1);
	return (0);
}
int	check_av(int ac, char *av[])
{
	if (check_av_isInt(ac, av))
		return (0);
	else if (check_av_double(ac, av))
		return (0);
	else
		return(ac - 1);
}