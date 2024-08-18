#include "../include/push_swap.h"

void rra(t_variable *var)
{
	var->t_list[0] = var->list_a[var->size_a - 1];
	cp_list(var->t_list + 1, var->list_a, var->size_a - 1);
	cp_list(var->list_a, var->t_list, var->size_a);
	var->next_move[0]--;
	var->next_move[1]--;
	var->count_mouv++;
};
void rrb(t_variable *var)
{
	var->t_list[0] = var->list_b[var->size_b - 1];
	cp_list(var->t_list + 1, var->list_b, var->size_b - 1);
	cp_list(var->list_b, var->t_list, var->size_b);
	var->next_move[0]--;
	var->next_move[2]--;
	var->count_mouv++;
};

void rrr(t_variable *var)
{
	rra(var);
	rrb(var);
	var->next_move[0]++;
	var->count_mouv--;
};
