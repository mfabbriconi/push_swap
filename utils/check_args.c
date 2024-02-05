/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:04:25 by mfabbric          #+#    #+#             */
/*   Updated: 2023/10/12 18:06:30 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_number(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

char	**fill_stack_values(t_stack *stack, int argc, char **argv)
{
	long int	nb;
	int			i;

	nb = 0;
	i = 1;
	stack->tempo = ft_calloc(sizeof(char *), argc);
	while (i < argc)
	{
		nb = ft_atoi(argv[i]);
		if (nb > 2147483647 || nb < -2147483648)
			ft_close();
		if (!ft_number(argv[i]))
			ft_close();
		if (ft_contains(nb, argv, i))
			ft_close();
		stack->tempo[i] = argv[i];
		i++;
	}
	stack->tempo[i] = 0;
	return (stack->tempo);
}

void	ft_check_args(t_stack *stack, int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;	

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = fill_stack_values(stack, argc, argv);
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_number(args[i]))
			ft_close();
		if (ft_contains(tmp, args, i))
			ft_close();
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_close();
		i++;
	}
	if (argc == 2)
		ft_free(args);
}
