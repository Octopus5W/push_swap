/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:06:49 by hdelbecq          #+#    #+#             */
/*   Updated: 2024/09/03 14:29:59 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../printf/libft.h"
# include <stdlib.h>

typedef struct s_variable
{
	int		list_a[500];
	int		size_a;
	int		list_b[500];
	int		size_b;
	int		t_list[500];
	int		next_move[6];
	int		count_move[6];
	int		max;
	int		min;
	int		i;
	int		j;
	char	**split;
}			t_variable;

void	algo(t_variable *var);

// print for correction
void	print_lists(t_variable var);
//

// UTILS files
int		ft_atoi(char *s);
char	*ft_itoa(int n);
char	**ft_split(char const *s);
int		check_av(int ac, char *av[], t_variable *var);
//

// UTILS1
int		count_move_down(int i);
int		count_move_up(int i, int max_i);
int		is_asc(int list[], int size);
int		*check_worth_move(t_variable *var);
//

// UTILS2
int		get_int_max(int list[], int len);
int		get_int_min(int list[], int len);
int		closest_int_down(int nb, int list[], int size);
int		closest_int_up(int nb, int list[], int size);
int		*cp_list(int *dst, int *src, int size);
//

// UTILS3
int		ft_atoi(char *s);
int		is_integer(char *s);
int		tab_is_integer(char *tab[]);
int		tab_is_duplicate(char *tab[]);
void	ft_free(t_variable *var);
//

// MOVE
char	*pa(t_variable *var);
char	*pb(t_variable *var);
char	*rra(t_variable *var);
char	*rrb(t_variable *var);
char	*rrr(t_variable *var);
char	*ra(t_variable *var);
char	*rb(t_variable *var);
char	*rr(t_variable *var);
char	*sa(t_variable *var);
char	*sb(t_variable *var);
char	*ss(t_variable *var);
//

#endif