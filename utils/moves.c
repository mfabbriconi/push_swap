/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 13:05:54 by mfabbric          #+#    #+#             */
/*   Updated: 2023/06/17 15:43:27 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(int *stack)
{
	int	tmp;
	
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}

void 	sa(t_stack *stack)
{
	swap(stack->stack_a);
	ft_putstr("sa\n");
}

void 	sb(t_stack *stack)
{
	swap(stack->stack_b);
	ft_putstr("sb\n");
}

void 	ss(t_stack *stack)
{
	swap(stack->stack_a);
	swap(stack->stack_b);
	ft_putstr("ss\n");
}