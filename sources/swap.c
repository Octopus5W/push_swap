#include "../include/push_swap.h"

char* sa(t_variable *var)
{
	var->t_list[0] = var->list_a[0];
	var->list_a[0] = var->list_a[1];
	var->list_a[1] = var->t_list[0];
	return ("sa\n");
};

char* sb(t_variable *var)
{
	var->t_list[0] = var->list_b[0];
	var->list_b[0] = var->list_b[1];
	var->list_b[1] = var->t_list[0];
	return ("sb\n");
};

char* ss(t_variable *var)
{
	sa(var);
	sb(var);
	return ("ss\n");
};
