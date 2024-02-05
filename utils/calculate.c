/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:49:22 by mfabbric          #+#    #+#             */
/*   Updated: 2023/07/17 14:39:29 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	max_min_insert(t_stack *stack, int i)
{
	if (i <= (stack->lunghezza / 2))
	{
		while (i > 0)
		{
			ra(stack);
			i--;
		}
	}
	else if (i > (stack->lunghezza / 2))
	{
		while (i < stack->lunghezza)
		{
			rra(stack);
			i++;
		}
	}
	pb(stack);
}

void	middle_insert(t_stack *stack, int i, int j)
{
	int	tmp;
	
	tmp = 2147483647;
	while (j <= stack->lunghezza_b)
	{
		if (stack->stack_a[i] > stack->stack_b[j])
		{
			if (tmp > (stack->stack_a[i] - stack->stack_b[j]))
			{
				// printf("tmp: %d\n", tmp);
				tmp = (stack->stack_a[i] - stack->stack_b[j]);
				stack->tmp = j;
			}
		}
		j++;
	}
	
}

void	bindex(t_stack *stack, int i, int j)
{
	int	tmp;
	
	tmp = 2147483647;
	while (j <= stack->lunghezza_b)
	{
		if (stack->stack_a[i] > stack->stack_b[j])
		{
			if (tmp > (stack->stack_a[i] - stack->stack_b[j]))
			{
				tmp = (stack->stack_a[i] - stack->stack_b[j]);
				stack->indexb = j;
			}
		}
		j++;
	}
}

int	max(t_stack *stack)
{
	int		i;
	int		max;
	int		posmax;

	i = 0;
	posmax = 0;
	max = stack->stack_b[0];
	while(++i < stack->lunghezza_b)
	{
		if (max < stack->stack_b[i])
		{
			max = stack->stack_b[i];
			posmax = i;
		}	
	}
	return(posmax);
}

void	last(t_stack *stack)
{
	int		i;
	int		posmax;

	posmax = max(stack);
	i = stack->lunghezza_b;
	if(posmax <= (stack->lunghezza_b / 2))
	{
		while (posmax > 0)
		{
			rb(stack);
			posmax--;
		}
	}
	else
	{
		while (posmax < stack->lunghezza_b)
		{
			rrb(stack);
			posmax++;
		}
	}	
	while (stack->lunghezza_b > 0)
		pa(stack);
}
