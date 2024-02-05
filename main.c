/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:36:23 by mfabbric          #+#    #+#             */
/*   Updated: 2023/10/12 18:06:45 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initstack(t_stack *stack, int argc, char **argv)
{
	int		j;
	char	**args;
	int		i;

	j = 0;
	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = &argv[1];
	}
	while (args[i])
		i++;
	stack->lunghezza = i;
	stack->stack_a = ft_calloc(sizeof(int), stack->lunghezza);
	stack->stack_b = ft_calloc(sizeof(int), stack->lunghezza);
	while (j < i)
	{
		(stack->stack_a)[j] = ft_atoi(args[j]);
		j++;
	}
	if (argc == 2)
		ft_free(args);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	stack.lunghezza_b = 0;
	if (argc < 2)
		return (0);
	ft_check_args(&stack, argc, argv);
	initstack(&stack, argc, argv);
	push_swap(&stack);
	free(stack.stack_a);
	free(stack.stack_b);
	free(stack.tempo);
	return (0);
}
