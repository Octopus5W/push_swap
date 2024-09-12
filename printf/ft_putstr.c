/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:59:04 by hdelbecq          #+#    #+#             */
/*   Updated: 2024/09/12 17:52:17 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_putstr(char *s)
{
	size_t	count;

	if (s)
	{
		count = ft_strlen(s);
		write(1, s, count);
		return (count);
	}
	return (0);
}
