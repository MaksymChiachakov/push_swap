/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_supp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:31:24 by mchiacha          #+#    #+#             */
/*   Updated: 2026/01/07 15:32:42 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	**split_str_supp(int i, char **res)
{
	while (--i >= 0)
		free(res[i]);
	free(res);
	return (NULL);
}

void	split_str_supp_len(int *i, int *j, char **res, const char *p)
{
	int	len;

	len = -1;
	while (++len < *j)
		res[*i][len] = p[len];
	res[*i][len] = '\0';
}

void	split_args_supp(char **tmp, char **all)
{
	int	j;
	int	total;

	j = 0;
	total = 0;
	while (tmp[j])
		all[total++] = tmp[j++];
	free(tmp);
	all[total] = NULL;
}
