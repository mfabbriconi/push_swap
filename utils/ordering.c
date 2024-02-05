/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordering.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:10:56 by roberto           #+#    #+#             */
/*   Updated: 2023/07/17 15:45:07 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	getmin(t_stack *stack)
{
	int		i;
	int		min;
	int		posmin;

	i = -1;
	posmin = 0;
	min = stack->stack_a[0];
	while (++i < stack->lunghezza)
	{
		if (min > stack->stack_a[i])
		{
			min = stack->stack_a[i];
			posmin = i;
		}
	}
	return (posmin);
}

int	getmax(t_stack *stack)
{
	int		i;
	int		max;
	int		posmax;

	i = -1;
	posmax = 0;
	max = stack->stack_a[0];
	while(++i < stack->lunghezza)
	{
		if (max < stack->stack_a[i])
		{
			max = stack->stack_a[i];
			posmax = i;
		}	
	}
	return(posmax);
}

int	is_sorted(t_stack *stack)
{
	int		i;

	i = 0;
	while (i < (stack->lunghezza - 1))
	{
		if (stack->stack_a[i] > stack->stack_a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	three_sort(t_stack *stack)
{
	if (stack->stack_a[0] == stack->max)
		ra(stack);
	if (stack->stack_a[1] == stack->max)
		rra(stack);
	if (stack->stack_a[0] > stack->stack_a[1])
		sa(stack);
}

void	push_swap(t_stack *stack)
{
	if (is_sorted(stack) == 0)
		return ;
	else if (stack->lunghezza == 2)
		sa(stack);
	else if (stack->lunghezza == 3)
		three_sort(stack);
	else if (stack->lunghezza > 3)
		sort(stack);
}
