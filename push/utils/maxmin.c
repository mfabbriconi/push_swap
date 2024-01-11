/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxmin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:11:35 by mfabbric          #+#    #+#             */
/*   Updated: 2023/10/09 11:13:58 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	getmin_b(t_stack *stack)
{
	int		i;
	int		min;

	i = -1;
	stack->min_b = 0;
	min = stack->stack_b[0];
	while (++i < stack->lunghezza_b)
	{
		if (min > stack->stack_b[i])
		{
			min = stack->stack_b[i];
			stack->min_b = i;
		}
	}
}

void	getmin_a(t_stack *stack)
{
	int		i;
	int		min;

	i = -1;
	stack->min_a = 0;
	min = stack->stack_a[0];
	while (++i < stack->lunghezza)
	{
		if (min > stack->stack_a[i])
		{
			min = stack->stack_a[i];
			stack->min_a = i;
		}
	}
}

void	getmax_b(t_stack *stack)
{
	int		i;
	int		max;

	i = -1;
	stack->max_b = 0;
	max = stack->stack_b[0];
	while (++i < stack->lunghezza_b)
	{
		if (max < stack->stack_b[i])
		{
			max = stack->stack_b[i];
			stack->max_b = i;
		}
	}
}

void	getmax_a(t_stack *stack)
{
	int		i;
	int		max;

	i = -1;
	stack->max_a = 0;
	max = stack->stack_a[0];
	while (++i < stack->lunghezza)
	{
		if (max < stack->stack_a[i])
		{
			max = stack->stack_a[i];
			stack->max_a = i;
		}
	}
}

void	get_maxmin(t_stack *stack)
{
	getmin_a(stack);
	getmin_b(stack);
	getmax_b(stack);
	getmax_a(stack);
}
