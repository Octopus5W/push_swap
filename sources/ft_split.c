/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:42:11 by hdelbecq          #+#    #+#             */
/*   Updated: 2024/05/06 21:48:31 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_tablen(char *s, char c)
{
	int	count;
	int	new;
	int	i;

	count = 0;
	new = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (new == 1)
				count++;
			new = 0;
		}
		else
			new = 1;
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

static int	ft_setalloc(char **dst, char *src, char c)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[i])
	{
		count = 0;
		while (src[i] && src[i] == c)
			i++;
		while (src[i] && src[i] != c)
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

static char	**ft_setstr(char **dst, char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	while (*s)
	{
		j = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			dst[i][j] = *s;
			s++;
			j++;
			if (*s == c || *s == '\0')
			{
				dst[i][j] = '\0';
				i++;
			}
		}
	}
	dst[i] = NULL;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		lenght;
	int		check;

	if (!s)
		return (NULL);
	lenght = ft_tablen((char *)s, c);
	tab = (char **)malloc(sizeof(char *) * (lenght + 1));
	if (!tab)
		return (NULL);
	check = ft_setalloc(tab, (char *)s, c);
	if (check-- > -1)
	{
		while (check >= 0)
			free(tab[check--]);
		free(tab);
		tab = NULL;
		return (tab);
	}
	ft_setstr(tab, (char *)s, c);
	return (tab);
}

/*
#include <stdio.h>
int main ()
{
	char c = 0;
	int i = 0;
	char **tab = ft_split("Hello!",' ');
	while (tab[i])
		printf("<%s>\n", tab[i++]);
}*/
