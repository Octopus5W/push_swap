#include "../include/push_swap.h"

int is_integer(const char *s)
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

int	ft_atoi(const char *s)
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

int	*get_av(int ac, const char *av[])
{
	int i;

	i = 0;
	if (ac <= 1)
		return (0);
	while (++i < ac && is_integer(av[i]))
		ft_atoi(av[i]);
}