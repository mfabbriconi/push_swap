/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:53:09 by mfabbric          #+#    #+#             */
/*   Updated: 2023/07/17 14:34:45 by mfabbric         ###   ########.fr       */
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
	int		tmp;

}	t_stack;

void	ft_check_args(int argc, char **argv);
void	ft_close(void);
void	ft_free(char **str);
void	ft_putstr(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t len);
int		absolute(int nb);
int		getmin(t_stack *stack);
int		getmax(t_stack *stack);

long long	ft_atoi(const char *str);
int			ft_isdigit(int c);
char		**ft_split(char const *s, char c);
void		push_swap(t_stack *stack);
void		sort(t_stack *stack);

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);

void	middle_insert(t_stack *stack, int i, int j);
void	max_min_insert(t_stack *stack, int i);
void	bindex(t_stack *stack, int i, int j);
void	three_sort(t_stack *stack);

void	move(t_stack *stack);
void	last(t_stack *stack);

#endif