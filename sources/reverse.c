#include "../include/push_swap.h"

void rra(t_variable var)
{
	var.t_list[0] = var.list_a[var.count_a - 1];
	cp_list(var.t_list + 1, var.list_a, var.count_a - 1);
	cp_list(var.list_a, var.t_list, var.count_a);
};
void rrb(t_variable var)
{
	var.t_list[0] = var.list_b[var.count_b - 1];
	cp_list(var.t_list + 1, var.list_b, var.count_b - 1);
	cp_list(var.list_b, var.t_list, var.count_b);
};

void rrr(t_variable var)
{
	rra(var);
	rrb(var);
};
