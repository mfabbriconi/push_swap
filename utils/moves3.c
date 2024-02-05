/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:13:14 by mfabbric          #+#    #+#             */
/*   Updated: 2023/10/09 11:09:27 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	revrotate(int *str, int lunghezza)
{
	int	i;
	int	tmp;

	i = lunghezza - 1;
	tmp = str[i];
	while (i > 0)
	{
		str[i] = str[i - 1];
		i--;
	}
	if (i == 0)
		str[i] = tmp;
}

void	rra(t_stack *stack)
{
	revrotate(stack->stack_a, stack->lunghezza);
	ft_putstr("rra\n");
}

void	rrb(t_stack *stack)
{
	revrotate(stack->stack_b, stack->lunghezza_b);
	ft_putstr("rrb\n");
}

void	rrr(t_stack *stack)
{
	revrotate(stack->stack_a, stack->lunghezza);
	revrotate(stack->stack_b, stack->lunghezza_b);
	ft_putstr("rrr\n");
}
