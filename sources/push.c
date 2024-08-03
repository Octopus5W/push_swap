#include "../include/push_swap.h"

void pa(t_variable var)
{
	var.t_list[0] = var.list_b[0];
	cp_list(var.t_list+1, var.list_a, var.count_a);
	var.count_a++;
	cp_list(var.list_a, var.t_list, var.count_a);
	var.count_b--;
	cp_list(var.t_list, var.list_b+1, var.count_b);	
	cp_list(var.list_b, var.t_list, var.count_b);
};

void pb(t_variable var)
{
	var.t_list[0] = var.list_a[0];
	cp_list(var.t_list+1, var.list_b, var.count_b);
	var.count_b++;
	cp_list(var.list_b, var.t_list, var.count_b);
	var.count_a--;
	cp_list(var.t_list, var.list_a+1, var.count_a);
	cp_list(var.list_a, var.t_list, var.count_a);
};