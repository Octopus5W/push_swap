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
	int	t_list[500];
	int	t_size;
	int next_move[6];
	int count_move[6];
	int count_nb;
	int max;
	int min;
	int median;
	int before;
	int after;
	int up;
	int down;
	int i;
	int j;
	char **split;
} t_variable;

void algo(t_variable *var);
void print_lists(t_variable var);
int	ft_atoi(char *s);
char	*ft_itoa(int n);
char	**ft_split(char const *s);
int	check_av(int ac, char *av[]);

// UTILS1
int count_move_down(int i);
int count_move_up(int i, int range_i);
int *check_worth_move(int *next_move, int i, int j, int range_i, int range_j);
int *cp_list(int *dst, int *src, int size);
void	ft_free(int size, char **tab);
//

//UTILS2
int get_int_max(int list[], int len);
int get_int_min(int list[], int len);
int get_int_median(int list[], int len);
int	closest_int_down(int nb, int list[], int size);
int	closest_int_up(int nb, int list[], int size);
//

//UTILS3
int	ft_atoi(char *s);
int is_integer(char *s);
int	tab_is_integer(char *tab[]);
int	tab_is_duplicate(char *tab[]);
int	is_asc(int list[], int size);
//

//UTILS4
int int_before(int list[], int index, int size);
int int_after(int list[], int index, int size);
// 


// MOVE
char* pa(t_variable *var);
char* pb(t_variable *var);
char* rra(t_variable *var);
char* rrb(t_variable *var);
char* rrr(t_variable *var);
char* ra(t_variable *var);
char* rb(t_variable *var);
char* rr(t_variable *var);
char* sa(t_variable *var);
char* sb(t_variable *var);
char* ss(t_variable *var);
//


#endif