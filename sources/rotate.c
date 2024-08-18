#include "../include/push_swap.h"

void ra (t_variable *var)
{

	cp_list(var->t_list, var->list_a + 1, var->size_a - 1);
	var->t_list[var->size_a - 1] = var->list_a[0];
	cp_list(var->list_a, var->t_list, var->size_a);
	var->next_move[0]--;
	var->next_move[1]--;
	var->count_mouv++;
};

void rb (t_variable *var)
{
	cp_list(var->t_list, var->list_b + 1, var->size_b - 1);
	var->t_list[var->size_b - 1] = var->list_b[0];
	cp_list(var->list_b, var->t_list, var->size_b);
	var->next_move[0]--;
	var->next_move[2]--;
	var->count_mouv++;
};

void rr (t_variable *var)
{
	ra(var);
	rb(var);
	var->next_move[0]++;
	var->count_mouv--;
};
