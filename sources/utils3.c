#include "../include/push_swap.h"

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
	if (*s == '+' || *s == '-')
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
	if (s[i] == '+')
		i++;
	while (s[i] == check[i] && check[i] && s[i])
		i++;
	if(!s[i] && !check[i])
		return(free(check), check = NULL, 1);
	return (free(check), check = NULL, 0);
}

int	tab_is_integer(char *tab[])
{
	int i;
	int size;

	if (!tab || !*tab || !**tab)
		return (0);
	i = -1;
	size = -1;
	while (tab[++size]);
	while (++i < size && is_integer(tab[i]));
	if (i == size)
		return (size);
	ft_printf("Only int are supported\n");
	return (0);
}

int	tab_is_duplicate(char *tab[])
{
	int i;
	int j;
	int check;
	int size;

	if (!tab || !*tab || !**tab)
		return (0);
	i = -1;
	size = -1;
	while (tab[++size]);
	while (++i < size && (j = i + 1))
	{
		check = ft_atoi(tab[i]);
		while (j < size && check != ft_atoi(tab[j]))
			j++;
		if (j < size)
		{
			ft_printf("Duplicate integer not allowed\n");
			return (j);
		}
	}
	return (0);
}

int	is_asc(int list[], int size)
{
	int i;

	i = -1;
	while (++i < size - 1)
	{
		if (list[i] > list[i + 1])
			return (0);
	}
	return(1);
}