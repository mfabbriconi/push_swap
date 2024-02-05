/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:18:01 by mfabbric          #+#    #+#             */
/*   Updated: 2023/06/23 16:32:38 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(int *src, int *dest, int lunghezza, int lunghezzasrc)
{
	int	i;

	i = lunghezza;
	while (i > 0)
	{
		dest[i] = dest[i - 1];
		i--;
	}
	if (i == 0)
		dest[i] = src[0];
	while (i < lunghezzasrc)
	{
		src[i] = src[i + 1];
		i++;
	}
}

void	pa(t_stack *stack)
{
	push(stack->stack_b, stack->stack_a, stack->lunghezza, stack->lunghezza_b);
	stack->lunghezza += 1;
	stack->lunghezza_b -= 1;
	ft_putstr("pa\n");
}

void	pb(t_stack *stack)
{
	push(stack->stack_a, stack->stack_b, stack->lunghezza_b, stack->lunghezza);
	stack->lunghezza -= 1;
	stack->lunghezza_b += 1;
	ft_putstr("pb\n");
}