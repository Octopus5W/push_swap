/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:05:29 by hdelbecq          #+#    #+#             */
/*   Updated: 2024/09/10 16:42:55 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_av(int ac, char *av[], t_variable *var)
{
	if (ac == 1)
		return (0);
	else if (ac > 2 && ac <= 501)
	{
		if (tab_is_integer(av + 1) && !tab_is_duplicate(av + 1))
			return (1);
		return (write(2, "Error\n", 6), 0);
	}
	else if (ac == 2)
	{
		var->split = ft_split(av[1]);
		if (!var->split)
			return (write(2, "Error\n", 6), 0);
		else if (tab_is_integer(var->split) && !tab_is_duplicate(var->split))
			return (ft_free(var), 1);
		else
			return (write(2, "Error\n", 6), ft_free(var), 0);
	}
	else
		return (0);
}
