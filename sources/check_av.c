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

int	check_av_isInt(int ac, const char *av[])
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

int	check_av_double(int ac, const char *av[])
{
	int i;
	int j;

	i = 0;
	if (ac <= 1)
		return (1);
	while (++i < ac && (j = i))
		while (++j < ac && ft_atoi(i) != ft_atoi(j));
	if (i != ac)
		return (1);
	return (0);
}
int	check_av(int ac, const char *av[])
{
	if (check_av_isInt(ac, av))
		return (0);
	else if (check_av_double(ac, av))
		return (0);
	else
		return(1);
}

// t_list *get_av_numbers(const char *av_numbers[])
// {
// 	t_list	*first_number;
// 	t_list	*current_number;
// 	t_list	*next_number;

// 	current_number->before_nb = NULL;
// 	current_number->nb = ft_atoi(*av_numbers++);
// 	current_number->after_nb = next_number;
// 	while (*av_numbers)



// }