/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:09:19 by mfabbric          #+#    #+#             */
/*   Updated: 2023/07/17 15:31:01 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	countmoves_a(t_stack *stack, int i)
{
	if (i == 0)
		return (1);
	else if (i <= stack->lunghezza / 2)
		return (i + 1);
	else
		return ((stack->lunghezza - i) + 1);
}

int	countmoves_b(t_stack *stack)
{
	if (stack->tmp == 0)
		return (0);
	else if (stack->tmp <= stack->lunghezza_b / 2)
		return (stack->tmp);
	else
		return (stack->lunghezza_b - stack->tmp);
}

int	rightchoise(int i, t_stack *stack, int j)
{
	middle_insert(stack, i, j);
	return (countmoves_a(stack, i) + countmoves_b(stack));
}

void	calculate(t_stack *stack, int flag)
{
	int		i;
	int		j;
	int		cost;
	int		tmp;

	i = 0;
	j = 0;
	if (flag == 0)
	{
		bindex(stack, i, j);
		flag++;
	}
	stack->indexa = 0;
	cost = rightchoise(i, stack, j);
	while (i < stack->lunghezza)
	{
		tmp = rightchoise(i, stack, j);
		if (tmp < cost)
		{
			cost = tmp;
			stack->indexa = i;
			stack->indexb = stack->tmp;
		}
		i++;
	}
}

void	sort(t_stack *stack)
{
	int k;
	int i;
	int flag;
	
	// i = 0;
	flag = 0;
	max_min_insert(stack, getmax(stack));
	max_min_insert(stack, getmin(stack));
	k = stack->lunghezza;
	while (k > 0)
	{
		calculate(stack, flag);
		// printf("A:[%d], B[%d]\n", stack->indexa, stack->indexb);
		move(stack);
		k--;
		// i = 0;
		// while (i < stack->lunghezza)
		// {
		// 	printf("stack_a[%d] = %d\n", i, stack->stack_a[i]);
		// 	i++;
		// }
		// printf("\n");
		// i = 0;
		// while (i < stack->lunghezza_b)
		// {
		// 	printf("stack_b[%d] = %d\n", i, stack->stack_b[i]);
		// 	i++;
		// }
	}
	last(stack);
	i = 0;
	while (i < stack->lunghezza)
	{
		printf("stack_a[%d] = %d\n", i, stack->stack_a[i]);
		i++;
	}
}	
