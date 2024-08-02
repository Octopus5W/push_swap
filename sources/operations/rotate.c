#include "../include/push_swap.h"

void ra (t_variable var)
{
	var.count_mouv++;
	ft_printf("ra\n");
	var.i = 1;
	var.t_count = 0;
	while (var.i < var.count_a - 1)
		var.t_list[var.t_count++] = var.list_a[var.i++];
	var.t_list[var.t_count++] = var.list_a[0];
	while (var.t_count)
		var.list_a[--var.t_count] = var.t_list[var.t_count];
};

void rb (t_variable var)
{
	var.count_mouv++;
	ft_printf("rb\n");
	var.i = 1;
	var.t_count = 0;
	while (var.i < var.count_b - 1)
		var.t_list[var.t_count++] = var.list_b[var.i++];
	var.t_list[var.t_count++] = var.list_b[0];
	while (var.t_count)
		var.list_b[--var.t_count] = var.t_list[var.t_count];
};

void rr (t_variable var)
{
	var.count_mouv--;
	ft_printf("rr\n");
	ra(var);
	rb(var);
};
