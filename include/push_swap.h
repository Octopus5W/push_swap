#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "../printf/libft.h"
# include <stdlib.h>

typedef struct s_variable
{
	int	list_a[500];
	int	size_a;
	int	list_b[500];
	int	size_b;
	int t_list[500];
	int t_size;
	int count_nb;
	int count_mouv;
	int i;
	int j;
	char **split;
} t_variable;

int	ft_atoi(char *s);
char	*ft_itoa(int n);
char	**ft_split(char const *s);
int	check_av(int ac, char *av[]);
int *cp_list(int *dst, int *src, int i);
void	ft_free(int size, char **tab);
void pa(t_variable *var);
void pb(t_variable *var);
void rra(t_variable *var);
void rrb(t_variable *var);
void rrr(t_variable *var);
void ra(t_variable *var);
void rb(t_variable *var);
void rr(t_variable *var);
void sa(t_variable *var);
void sb(t_variable *var);
void ss(t_variable *var);

#endif