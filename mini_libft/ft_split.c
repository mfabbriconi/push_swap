/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfabbric <mfabbric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:37:36 by mfabbric          #+#    #+#             */
/*   Updated: 2023/01/20 16:46:24 by mfabbric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	strlen_neg_pos(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static int	count_nbr_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*copy_words(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		start;
	int		j;

	split = malloc((count_nbr_words(s, c) + 1) * sizeof(char *));
	if (!split || !s)
		return (0);
	start = -1;
	i = 0;
	j = 0;
	while (i <= strlen_neg_pos(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == strlen_neg_pos(s)) && start >= 0)
		{
			split[j++] = copy_words(s, start, i);
			start = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
