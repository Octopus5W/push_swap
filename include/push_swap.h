#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "../printf/libft.h"

struct list
{
	struct list*	before_nb;
	int		nb;
	struct list*	after_nb;
};

struct list pa(struct list a, struct list b);
struct list pb(struct list a, struct list b);
struct list rra(struct list a);
struct list rrb(struct list b);
struct list rrr(struct list a , struct list b);
struct list ra(struct list a);
struct list rb(struct list b);
struct list rr(struct list a , struct list b);
struct list sa(struct list a);
struct list sb(struct list b);
struct list ss(struct list a , struct list b);

#endif