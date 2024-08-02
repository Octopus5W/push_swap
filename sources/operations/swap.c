#include "../include/push_swap.h"

void sa(t_variable var)
{
	var.count_mouv++;
	ft_printf("sa\n");
	var.t_list[0] = var.list_a[0];
	var.list_a[0] = var.list_a[1];
	var.list_a[1] = var.t_list[0];
};

void sb(t_variable var)
{
	var.count_mouv++;
	ft_printf("sb\n");
	var.t_list[0] = var.list_b[0];
	var.list_b[0] = var.list_b[1];
	var.list_b[1] = var.t_list[0];
};

void ss(t_variable var)
{
	var.count_mouv--;
	ft_printf("ss\n");
	sa(var);
	sb(var);

};
