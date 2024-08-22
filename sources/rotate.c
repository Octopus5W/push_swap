#include "../include/push_swap.h"

char* ra (t_variable *var)
{

	cp_list(var->t_list, var->list_a + 1, var->size_a - 1);
	var->t_list[var->size_a - 1] = var->list_a[0];
	cp_list(var->list_a, var->t_list, var->size_a);
	return ("ra\n");
};

char* rb (t_variable *var)
{
	cp_list(var->t_list, var->list_b + 1, var->size_b - 1);
	var->t_list[var->size_b - 1] = var->list_b[0];
	cp_list(var->list_b, var->t_list, var->size_b);
	return ("rb\n");
};

char* rr (t_variable *var)
{
	ra(var);
	rb(var);
	return ("rr\n");
};
