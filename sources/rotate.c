#include "../include/push_swap.h"

void ra (t_variable var)
{

	cp_list(var.t_list, var.list_a + 1, var.count_a - 1);
	var.t_list[var.count_a - 1] = var.list_a[0];
	cp_list(var.list_a, var.t_list, var.count_a);
};

void rb (t_variable var)
{
	cp_list(var.t_list, var.list_b + 1, var.count_b - 1);
	var.t_list[var.count_b - 1] = var.list_b[0];
	cp_list(var.list_b, var.t_list, var.count_b);
};

void rr (t_variable var)
{
	ra(var);
	rb(var);
};
