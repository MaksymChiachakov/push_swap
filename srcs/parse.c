/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:28:19 by mchiacha          #+#    #+#             */
/*   Updated: 2026/01/07 14:28:20 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	count_words(const char *s)
{
	int	in;
	int	i;

	in = 0;
	i = 0;
	while (s && *s)
	{
		if (*s != ' ' && in == 0)
		{
			in = 1;
			i++;
		}
		else if (*s == ' ')
			in = 0;
		s++;
	}
	return (i);
}

char	**split_str(const char *s)
{
	int			words;
	char		**res;
	int			i;
	int			j;

	words = count_words(s);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < words)
	{
		while (*s == ' ')
			s++;
		j = 0;
		while (s[j] && s[j] != ' ')
			j++;
		res[i] = malloc(j + 1);
		if (!res[i])
			return (split_str_supp(i, res), NULL);
		split_str_supp_len(&i, &j, res, s);
		s += j;
	}
	res[words] = NULL;
	return (res);
}

char	**split_args(int argc, char **argv)
{
	char	**all;
	char	**tmp;
	int		i;

	all = malloc(sizeof(char *) * 1000);
	if (!all)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) == 0)
			continue ;
		tmp = split_str(argv[i]);
		if (!tmp)
			return (NULL);
		split_args_supp(tmp, all);
		i++;
	}
	return (all);
}
