/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:06:09 by hdelbecq          #+#    #+#             */
/*   Updated: 2024/09/03 12:06:10 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*ra(t_variable *var)
{
	cp_list(var->t_list, var->list_a + 1, var->size_a - 1);
	var->t_list[var->size_a - 1] = var->list_a[0];
	cp_list(var->list_a, var->t_list, var->size_a);
	var->next_move[0]--;
	return ("ra\n");
}

char	*rb(t_variable *var)
{
	cp_list(var->t_list, var->list_b + 1, var->size_b - 1);
	var->t_list[var->size_b - 1] = var->list_b[0];
	cp_list(var->list_b, var->t_list, var->size_b);
	var->next_move[2]--;
	return ("rb\n");
}

char	*rr(t_variable *var)
{
	ra(var);
	rb(var);
	return ("rr\n");
}
