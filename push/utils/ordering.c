/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordering.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:10:56 by roberto           #+#    #+#             */
/*   Updated: 2023/10/12 15:49:52 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	get_maxmin(stack);
	if (0 == stack->max_a)
		ra(stack);
	if (1 == stack->max_a)
		rra(stack);
	if (stack->stack_a[0] > stack->stack_a[1])
		sa(stack);
	get_maxmin(stack);
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
