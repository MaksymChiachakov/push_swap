/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:26:16 by mchiacha          #+#    #+#             */
/*   Updated: 2026/01/07 14:26:18 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_min_pos(t_stack *s)
{
	int	pos;
	int	min;
	int	i;

	pos = 0;
	i = 1;
	min = s->a[0];
	while (i < s->size_a)
	{
		if (s->a[i] < min)
		{
			min = s->a[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

void	push_min_to_b(t_stack *s)
{
	int	size;
	int	pos;

	pos = find_min_pos(s);
	size = s->size_a;
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(s);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(s);
	}
	pb(s);
}
