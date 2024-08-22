#include "push_swap.h"

void algo(t_variable *var)
{
	//
	while (var->size_a)
	{
		var->min = get_int_min(var->list_a, var->size_a);
		var->max = get_int_max(var->list_a, var->size_a);
		
	}
}