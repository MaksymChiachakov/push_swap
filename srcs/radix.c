/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:37:50 by mchiacha          #+#    #+#             */
/*   Updated: 2026/01/07 13:38:01 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	radix_with_ops(t_stack *s)
{
	int	max_bits;
	int	size;
	int	max;
	int	i;
	int	j;

	max = s->size_a - 1;
	max_bits = 0;
	i = -1;
	while ((1 << max_bits) <= max)
		max_bits++;
	while (++i < max_bits)
	{
		size = s->size_a;
		j = -1;
		while (++j < size)
		{
			if ((s->a[0] >> i) & 1)
				ra(s);
			else
				pb(s);
		}
		while (s->size_b > 0)
			pa(s);
	}
}
