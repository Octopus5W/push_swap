#include "../include/push_swap.h"

char* pa(t_variable *var)
{
	var->t_list[0] = var->list_b[0];
	cp_list(var->t_list+1, var->list_a, var->size_a);
	var->size_a++;
	cp_list(var->list_a, var->t_list, var->size_a);
	var->size_b--;
	cp_list(var->t_list, var->list_b+1, var->size_b);	
	cp_list(var->list_b, var->t_list, var->size_b);
	return("pa\n");
};

char* pb(t_variable *var)
{
	var->t_list[0] = var->list_a[0];
	cp_list(var->t_list+1, var->list_b, var->size_b);
	var->size_b++;
	cp_list(var->list_b, var->t_list, var->size_b);
	var->size_a--;
	cp_list(var->t_list, var->list_a+1, var->size_a);
	cp_list(var->list_a, var->t_list, var->size_a);
	return("pb\n");
};