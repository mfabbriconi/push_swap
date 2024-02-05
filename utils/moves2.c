/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:47:01 by mfabbric          #+#    #+#             */
/*   Updated: 2023/10/09 11:10:06 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(int *str, int lunghezza)
{
	int	i;
	int	temp;

	i = 0;
	temp = str[0];
	while (i < lunghezza)
	{
		str[i] = str[i + 1];
		i++;
	}
	str[lunghezza - 1] = temp;
}

void	ra(t_stack *stack)
{
	rotate(stack->stack_a, stack->lunghezza);
	ft_putstr("ra\n");
}

void	rb(t_stack *stack)
{
	rotate(stack->stack_b, stack->lunghezza_b);
	ft_putstr("rb\n");
}

void	rr(t_stack *stack)
{
	rotate(stack->stack_a, stack->lunghezza);
	rotate(stack->stack_b, stack->lunghezza_b);
	ft_putstr("rr\n");
}
