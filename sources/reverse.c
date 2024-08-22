#include "../include/push_swap.h"

char* rra(t_variable *var)
{
	var->t_list[0] = var->list_a[var->size_a - 1];
	cp_list(var->t_list + 1, var->list_a, var->size_a - 1);
	cp_list(var->list_a, var->t_list, var->size_a);
	return ("rra\n");
};
char* rrb(t_variable *var)
{
	var->t_list[0] = var->list_b[var->size_b - 1];
	cp_list(var->t_list + 1, var->list_b, var->size_b - 1);
	cp_list(var->list_b, var->t_list, var->size_b);
	return ("rrb\n");
};

char* rrr(t_variable *var)
{
	rra(var);
	rrb(var);
	return ("rrr\n");
};
