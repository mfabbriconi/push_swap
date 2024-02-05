/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:58:27 by mfabbric          #+#    #+#             */
/*   Updated: 2023/10/09 11:24:17 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	first_first(t_stack *stack)
{
	while (stack->indexb != 0 && stack->indexa != 0)
	{
		rr(stack);
		stack->indexa--;
		stack->indexb--;
	}
	while (stack->indexa != 0)
	{
		ra(stack);
		stack->indexa--;
	}
	while (stack->indexb != 0)
	{
		rb(stack);
		stack->indexb--;
	}
}

void	first_second(t_stack *stack)
{
	while (stack->indexa != 0)
	{
		ra(stack);
		stack->indexa--;
	}
	while (stack->indexb < stack->lunghezza_b)
	{
		rrb(stack);
		stack->indexb++;
	}
}

void	second_first(t_stack *stack)
{
	while (stack->indexa < stack->lunghezza)
	{
		rra(stack);
		stack->indexa++;
	}
	while (stack->indexb != 0)
	{
		rb(stack);
		stack->indexb--;
	}
}

void	second_second(t_stack *stack)
{
	int	i;

	i = -1;
	if (stack->lunghezza - stack->indexa > stack->lunghezza_b - stack->indexb)
	{
		while (++i < stack->lunghezza_b - stack->indexb)
			rrr(stack);
		i = -1;
		while (++i < (stack->lunghezza - stack->indexa)
			- (stack->lunghezza_b - stack->indexb))
			rra(stack);
	}
	else
	{
		i = -1;
		while (++i < stack->lunghezza - stack->indexa)
			rrr(stack);
		i = -1;
		while (++i < (stack->lunghezza_b - stack->indexb)
			- (stack->lunghezza - stack->indexa))
			rrb(stack);
	}
}

void	move(t_stack *stack, int s)
{
	int	half_a;
	int	half_b;

	if (stack->lunghezza % 2 == 0)
		half_a = stack->lunghezza / 2;
	else
		half_a = stack->lunghezza / 2 + 1;
	if (stack->lunghezza_b % 2 == 0)
		half_b = stack->lunghezza_b / 2;
	else
		half_b = stack->lunghezza_b / 2 + 1;
	if (stack->indexa < half_a && stack->indexb < half_b)
		first_first(stack);
	else if (stack->indexa >= half_a && stack->indexb >= half_b)
		second_second(stack);
	else if (stack->indexa < half_a && stack->indexb >= half_b)
		first_second(stack);
	else if (stack->indexa >= half_a && stack->indexb < half_b)
		second_first(stack);
	if (s == 1)
		pb(stack);
	else
		pa(stack);
}
