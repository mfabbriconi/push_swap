/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:49:22 by mfabbric          #+#    #+#             */
/*   Updated: 2023/10/09 14:48:01 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_index(t_stack *stack, int i)
{
	int	j;

	j = 0;
	stack->tmp_a = 0;
	stack->tmp_b = i;
	if (stack->stack_b[i] > stack->stack_a[stack->max_a]
		|| stack->stack_b[i] < stack->stack_a[stack->min_a])
		stack->tmp_a = stack->min_a;
	while (j < stack->lunghezza - 1)
	{
		if (stack->stack_b[i] > stack->stack_a[j]
			&& stack->stack_b[i] < stack->stack_a[j + 1])
			stack->tmp_a = j + 1;
		j++;
	}
}

void	bindex(t_stack *stack, int i)
{
	int	j;

	j = 0;
	stack->tmp_b = 0;
	stack->tmp_a = i;
	if (stack->stack_a[i] > stack->stack_b[stack->max_b]
		|| stack->stack_a[i] < stack->stack_b[stack->min_b])
		stack->tmp_b = stack->max_b;
	while (j < stack->lunghezza_b - 1)
	{
		if (stack->stack_a[i] < stack->stack_b[j]
			&& stack->stack_a[i] > stack->stack_b[j + 1])
			stack->tmp_b = j + 1;
		j++;
	}
}

void	last(t_stack *stack)
{
	int	i;

	i = -1;
	if (stack->min_a < stack->lunghezza / 2)
		while (++i < stack->min_a)
			ra(stack);
	else
		while (++i < stack->lunghezza - stack->min_a)
			rra(stack);
}
