/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:06:03 by hdelbecq          #+#    #+#             */
/*   Updated: 2024/09/03 12:06:04 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*rra(t_variable *var)
{
	var->t_list[0] = var->list_a[var->size_a - 1];
	cp_list(var->t_list + 1, var->list_a, var->size_a - 1);
	cp_list(var->list_a, var->t_list, var->size_a);
	var->next_move[0]++;
	if (var->next_move[0] == var->size_a)
		var->next_move[0] = 0;
	return ("rra\n");
}

char	*rrb(t_variable *var)
{
	var->t_list[0] = var->list_b[var->size_b - 1];
	cp_list(var->t_list + 1, var->list_b, var->size_b - 1);
	cp_list(var->list_b, var->t_list, var->size_b);
	var->next_move[2]++;
	if (var->next_move[2] == var->size_b)
		var->next_move[2] = 0;
	return ("rrb\n");
}

char	*rrr(t_variable *var)
{
	rra(var);
	rrb(var);
	return ("rrr\n");
}
