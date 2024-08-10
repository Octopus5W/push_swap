/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:57:27 by hdelbecq          #+#    #+#             */
/*   Updated: 2024/04/23 18:57:32 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_nbsize(int n)
{
	int	size;

	size = 1;
	if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		n *= -1;
		size++;
	}
	while (n > 9)
	{
		size += 1;
		n /= 10;
	}
	return (size);
}

static char	*get_condition(char *s, int n, int i)
{
	if (n == -2147483648)
	{
		while (i >= 0)
		{
			s[i] = "-2147483648"[i];
			i--;
		}
	}
	else if (n == 0)
		s[i] = '0';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		i;

	i = ft_nbsize(n);
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (0);
	s[i--] = '\0';
	get_condition(s, n, i);
	if (n < 0 && n > -2147483648)
	{
		n *= -1;
		s[0] = '-';
	}
	while (n > 0)
	{
		s[i--] = n % 10 + '0';
		n /= 10;
	}
	return (s);
}
// #include <stdio.h>
// #include <stdlib.h>
// int	main(void)
// {
// 	printf("<%s>\n", ft_itoa(-2147483647 -1));
// 	printf("<%s>", itoa(-2147483648));
// }
