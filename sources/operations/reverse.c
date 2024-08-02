#include "../include/push_swap.h"

void rra(t_variable var)
{
	var.count_mouv++;
	ft_printf("rra\n");
	var.i = 0;
	var.t_count = 0;
	var.t_list[0] = var.list_a[var.count_a - 1];
	while (var.i < var.count_a - 1)
		var.t_list[var.t_count++] = var.list_a[var.i++];
	while (var.t_count)
		var.list_a[--var.t_count] = var.t_list[var.t_count];
};
void rrb(t_variable var)
{
	var.count_mouv++;
	ft_printf("rrb\n");
	var.i = 0;
	var.t_count = 0;
	var.t_list[0] = var.list_b[var.count_b - 1];
	while (var.i < var.count_b - 1)
		var.t_list[var.t_count++] = var.list_b[var.i++];
	while (var.t_count)
		var.list_b[--var.t_count] = var.t_list[var.t_count];
};

void rrr(t_variable var)
{
	var.count_mouv--;
	ft_printf("rrr\n");
	rra(var);
	rrb(var);
};
