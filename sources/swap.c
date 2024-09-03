/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:06:13 by hdelbecq          #+#    #+#             */
/*   Updated: 2024/09/03 12:06:14 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*sa(t_variable *var)
{
	var->t_list[0] = var->list_a[0];
	var->list_a[0] = var->list_a[1];
	var->list_a[1] = var->t_list[0];
	return ("sa\n");
}

char	*sb(t_variable *var)
{
	var->t_list[0] = var->list_b[0];
	var->list_b[0] = var->list_b[1];
	var->list_b[1] = var->t_list[0];
	return ("sb\n");
}

char	*ss(t_variable *var)
{
	sa(var);
	sb(var);
	return ("ss\n");
}
