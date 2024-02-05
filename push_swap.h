/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:53:09 by mfabbric          #+#    #+#             */
/*   Updated: 2023/10/12 17:47:54 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>

typedef struct s_stack
{
	int		*stack_a;
	int		*stack_b;
	int		lunghezza;
	int		lunghezza_b;
	int		max;
	int		min;
	int		indexa;
	int		indexb;
	int		min_a;
	int		min_b;
	int		max_a;
	int		max_b;
	int		half_a;
	int		half_b;
	int		tmp_mov;
	int		tmp_b;
	int		tmp_a;
	int		moves;
	int		tmp;
	char	**tempo;
}	t_stack;

void		ft_check_args(t_stack *stack, int argc, char **argv);
void		ft_close(void);
void		ft_free(char **str);
void		ft_putstr(char *str);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *s, int c, size_t len);
int			absolute(int nb);
void		get_maxmin(t_stack *stack);

long long	ft_atoi(const char *str);

int			ft_isdigit(int c);
char		**ft_split(char const *s, char c);
void		push_swap(t_stack *stack);
void		sort(t_stack *stack);

void		sa(t_stack *stack);
void		sb(t_stack *stack);
void		ss(t_stack *stack);
void		ra(t_stack *stack);
void		rb(t_stack *stack);
void		rr(t_stack *stack);
void		rra(t_stack *stack);
void		rrb(t_stack *stack);
void		rrr(t_stack *stack);
void		pa(t_stack *stack);
void		pb(t_stack *stack);

void		bindex(t_stack *stack, int i);
void		ft_index(t_stack *stack, int i);
void		three_sort(t_stack *stack);

void		count_mv(t_stack *stack);
void		count_mv_2(t_stack *stack);
void		move(t_stack *stack, int s);
void		last(t_stack *stack);

#endif