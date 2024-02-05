/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:09:19 by mfabbric          #+#    #+#             */
/*   Updated: 2023/11/09 14:44:43 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	calculate(t_stack *stack)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < stack->lunghezza_b)
	{
		ft_index(stack, i);
		count_mv_2(stack);
	}
}

void	calculate_1(t_stack *stack)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < stack->lunghezza)
	{
		bindex(stack, i);
		count_mv(stack);
	}
}

void	sort(t_stack *stack)
{
	int	k;

	pb(stack);
	pb(stack);
	k = stack->lunghezza;
	while (k > 3)
	{
		calculate_1(stack);
		move(stack, 1);
		k--;
	}
	three_sort(stack);
	k = stack->lunghezza_b;
	while (k > 0)
	{
		calculate(stack);
		move(stack, 0);
		k--;
	}
	last(stack);
}
