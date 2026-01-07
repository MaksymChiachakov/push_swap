/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:39:42 by mchiacha          #+#    #+#             */
/*   Updated: 2026/01/07 13:39:43 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	parse_integers(char **tokens, int **out_arr, int *out_n)
{
	int		n;
	int		*arr;
	int		i;
	long	v;

	n = 0;
	while (tokens && tokens[n])
		n++;
	arr = malloc(sizeof(int) * n);
	if (!arr)
		return (0);
	i = 0;
	while (i < n)
	{
		v = ft_atol(tokens[i]);
		if (v > INT_MAX || v < INT_MIN)
			return (free(arr), 0);
		arr[i] = (int)v;
		i++;
	}
	*out_arr = arr;
	*out_n = n;
	return (1);
}

int	check_duplicates(int *arr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
