#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "../printf/libft.h"

typedef struct s_list
{
	t_list*	before_nb;
	int		nb;
	t_list*	after_nb;
} t_list;

t_list pa(t_list a, t_list b);
t_list pb(t_list a, t_list b);
t_list rra(t_list a);
t_list rrb(t_list b);
t_list rrr(t_list a , t_list b);
t_list ra(t_list a);
t_list rb(t_list b);
t_list rr(t_list a , t_list b);
t_list sa(t_list a);
t_list sb(t_list b);
t_list ss(t_list a , t_list b);

#endif