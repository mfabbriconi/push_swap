/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:17:42 by mfabbric          #+#    #+#             */
/*   Updated: 2023/10/09 15:32:22 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	gethalf(t_stack *stack, int flag)
{
	int	half;

	if (flag == 0)
	{
		if (stack->lunghezza % 2 == 0)
			half = stack->lunghezza / 2;
		else
			half = stack->lunghezza / 2 + 1;
	}
	else
	{
		if (stack->lunghezza_b % 2 == 0)
			half = stack->lunghezza_b / 2;
		else
			half = stack->lunghezza_b / 2 + 1;
	}
	return (half);
}

static void	tmpmoves(t_stack *stack, int flag)
{
	if (flag == 0)
	{
		if (stack->tmp_a == 0 || stack->tmp_mov < stack->moves)
		{
			stack->indexa = stack->tmp_a;
			stack->indexb = stack->tmp_b;
			stack->moves = stack->tmp_mov;
		}
	}
	else
	{
		if (stack->tmp_b == 0 || stack->tmp_mov < stack->moves)
		{
			stack->indexa = stack->tmp_a;
			stack->indexb = stack->tmp_b;
			stack->moves = stack->tmp_mov;
		}
	}
}

void	count_mv(t_stack *stack)
{
	stack->half_a = gethalf(stack, 0);
	stack->half_b = gethalf(stack, 1);
	if (stack->tmp_a < stack->half_a && stack->tmp_b < stack->half_b)
	{
		if (stack->tmp_a < stack->tmp_b)
			stack->tmp_mov = stack->tmp_b;
		else
			stack->tmp_mov = stack->tmp_a;
	}
	else if (stack->tmp_a >= stack->half_a && stack->tmp_b >= stack->half_b)
	{
		if (stack->lunghezza - stack->tmp_a
			> stack->lunghezza_b - stack->tmp_b)
			stack->tmp_mov = stack->lunghezza - stack->tmp_a;
		else
			stack->tmp_mov = stack->lunghezza_b - stack->tmp_b;
	}
	else
	{
		if (stack->tmp_a < stack->half_a && stack->tmp_b >= stack->half_b)
			stack->tmp_mov = stack->tmp_a + (stack->lunghezza_b - stack->tmp_b);
		else
			stack->tmp_mov = stack->tmp_b + (stack->lunghezza - stack->tmp_a);
	}
	tmpmoves(stack, 0);
}

void	count_mv_2(t_stack *stack)
{
	stack->half_a = gethalf(stack, 0);
	stack->half_b = gethalf(stack, 1);
	if (stack->tmp_a < stack->half_a && stack->tmp_b < stack->half_b)
	{
		if (stack->tmp_a < stack->tmp_b)
			stack->tmp_mov = stack->tmp_b;
		else
			stack->tmp_mov = stack->tmp_a;
	}
	else if (stack->tmp_a >= stack->half_a && stack->tmp_b >= stack->half_b)
	{
		if (stack->lunghezza - stack->tmp_a > stack->lunghezza_b - stack->tmp_b)
			stack->tmp_mov = stack->lunghezza - stack->tmp_a;
		else
			stack->tmp_mov = stack->lunghezza_b - stack->tmp_b;
	}
	else
	{
		if (stack->tmp_a < stack->half_a && stack->tmp_b >= stack->half_b)
			stack->tmp_mov = stack->tmp_a + (stack->lunghezza_b - stack->tmp_b);
		else
			stack->tmp_mov = stack->tmp_b + (stack->lunghezza - stack->tmp_a);
	}
	tmpmoves(stack, 1);
}
