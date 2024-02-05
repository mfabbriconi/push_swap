/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:58:27 by mfabbric          #+#    #+#             */
/*   Updated: 2023/07/17 13:28:22 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	first_first(t_stack *stack)
{
	while (stack->indexa > 0)
	{
		ra(stack);
		stack->indexa--;
	}
	while (stack->indexb > 0)
	{
		rb(stack);
		stack->indexb--;
	}
	if (stack->indexa == 0 && stack->indexb == 0)
		pb(stack);
}

void	first_second(t_stack *stack)
{
	while (stack->indexa > 0)
	{
		ra(stack);
		stack->indexa--;
	}
	while (stack->indexb < stack->lunghezza_b)
	{
		rrb(stack);
		stack->indexb++;
	}
	if (stack->indexa == 0 && stack->indexb == stack->lunghezza_b)
		pb(stack);
}

void	second_first(t_stack *stack)
{
	while (stack->indexa < stack->lunghezza)
	{
		rra(stack);
		stack->indexa++;
	}
	while (stack->indexb > 0)
	{
		rb(stack);
		stack->indexb--;
	}
	if (stack->indexa == stack->lunghezza && stack->indexb == 0)
		pb(stack);
}

void	second_second(t_stack *stack)
{
	while (stack->indexa < stack->lunghezza)
	{
		rra(stack);
		stack->indexa++;
	}
	while (stack->indexb < stack->lunghezza_b)
	{
		rrb(stack);
		stack->indexb++;
	}
	if (stack->indexa == stack->lunghezza && stack->indexb == stack->lunghezza_b)
		pb(stack);
}

void	move(t_stack *stack)
{
	if (stack->indexa <= (stack->lunghezza / 2) && stack->indexb <= (stack->lunghezza / 2))
		first_first(stack);
	else if (stack->indexa <= (stack->lunghezza / 2)
			&& stack->indexb > (stack->lunghezza / 2))
		first_second(stack);
	else if (stack->indexa > (stack->lunghezza / 2)
			&& stack->indexb <= (stack->lunghezza / 2))
		second_first(stack);
	else if (stack->indexa > (stack->lunghezza / 2)
			&& stack->indexb > (stack->lunghezza / 2))	
		second_second(stack);
}