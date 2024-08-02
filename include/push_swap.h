#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "../printf/libft.h"

typedef struct s_variable
{
	int	list_a[500];
	int	count_a;
	int	list_b[500];
	int	count_b;
	int t_list[500];
	int t_count;
	int count_nb;
	int count_mouv;
	int i;
	int j;
} t_variable;

int	ft_atoi(char *s);
int	check_av(int ac, char *av[]);
t_variable pa(t_variable var);
t_variable pb(t_variable var);
t_variable rra(t_variable var);
t_variable rrb(t_variable var);
t_variable rrr(t_variable var);
t_variable ra(t_variable var);
t_variable rb(t_variable var);
t_variable rr(t_variable var);
t_variable sa(t_variable var);
t_variable sb(t_variable var);
t_variable ss(t_variable var);

#endif