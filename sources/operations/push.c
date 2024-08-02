#include "../include/push_swap.h"

void pa(t_variable var)
{
	ft_printf("pa\n");
	var.count_mouv++;
	var.i = 0;
	var.t_count = 0;
	var.t_list[var.t_count] = var.list_b[var.t_count++];
	while (var.i < var.count_a)
		var.t_list[var.t_count++] = var.list_a[var.i++];
	var.count_a++;
	var.i = 0;
	while (var.i < var.count_a)
		var.list_a[var.i] = var.t_list[var.i++];
	var.t_count = 0;
	while (var.t_count < var.count_b)
		var.list_b[var.t_count] = var.list_b[++var.t_count];	
	var.count_b--;
	var.t_count = 0;
	while (var.t_count < var.count_b)
		var.list_b[var.t_count] = var.t_list[var.t_count++];
};

void pb(t_variable var)
{
	var.count_mouv++;
	ft_printf("pb\n");
	var.i = 0;
	var.t_count = 0;
	var.t_list[var.t_count] = var.list_a[var.t_count++];
	while (var.i < var.count_b)
		var.t_list[var.t_count++] = var.list_b[var.i++];
	var.count_b++;
	var.i = 0;
	while (var.i < var.count_b)
		var.list_b[var.i] = var.t_list[var.i++];
	var.t_count = 0;
	while (var.t_count < var.count_a)
		var.list_a[var.t_count] = var.list_a[++var.t_count];	
	var.count_a--;
	var.t_count = 0;
	while (var.t_count < var.count_a)
		var.list_a[var.t_count] = var.t_list[var.t_count++];
};