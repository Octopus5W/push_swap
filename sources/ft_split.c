/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:05:44 by hdelbecq          #+#    #+#             */
/*   Updated: 2024/09/03 12:05:44 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_tablen(char *s)
{
	int	count;
	int	new;
	int	i;

	count = 0;
	new = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == ' ' || (s[i] >= 7 && s[i] <= 13))
			new = 1;
		else
		{
			if (new == 1)
			{
				new = 0;
				count++;
			}
		}
		i++;
	}
	return (count);
}

static char	*ft_malloc(char *s, int count)
{
	s = malloc(sizeof(char) * (count + 1));
	if (!s)
		return (0);
	return (s);
}

static int	ft_setalloc(char **dst, char *src)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[i])
	{
		count = 0;
		while (src[i] && (src[i] == ' ' || (src[i] >= 7 && src[i] <= 13)))
			i++;
		while (src[i] && src[i] != ' ' && (src[i] <= 7 || src[i] >= 13))
		{
			count++;
			i++;
		}
		if (count > 0)
		{
			dst[j] = ft_malloc(dst[j], count);
			if (!dst[j])
				return (j);
			j++;
		}
	}
	return (-1);
}

static char	**ft_setstr(char **dst, char *s)
{
	int	i;
	int	j;

	i = 0;
	while (*s)
	{
		j = 0;
		while ((*s == ' ' || (*s >= 7 && *s <= 13)) && *s)
			s++;
		while (*s != ' ' && (*s < 7 || *s > 13) && *s)
		{
			dst[i][j] = *s;
			s++;
			j++;
			if (*s == ' ' || (*s >= 7 && *s <= 13) || *s == '\0')
			{
				dst[i][j] = '\0';
				i++;
			}
		}
	}
	dst[i] = NULL;
	return (dst);
}

char	**ft_split(char const *s)
{
	char	**tab;
	int		lenght;
	int		check;

	if (!s)
		return (NULL);
	lenght = ft_tablen((char *)s);
	if (lenght < 2 || lenght > 500)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (lenght + 1));
	if (!tab)
		return (NULL);
	check = ft_setalloc(tab, (char *)s);
	if (check > -1)
	{
		while (check >= 0)
			free(tab[check--]);
		free(tab);
		tab = NULL;
		return (tab);
	}
	ft_setstr(tab, (char *)s);
	return (tab);
}
