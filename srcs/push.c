/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:28:11 by mchiacha          #+#    #+#             */
/*   Updated: 2026/01/07 14:28:13 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* push a->b */
void	pb(t_stack *s)
{
	int	i;

	i = s->size_b;
	while (i > 0)
	{
		s->b[i] = s->b[i - 1];
		i--;
	}
	if (s->size_a > 0)
		s->b[0] = s->a[0];
	s->size_b++;
	i = 0;
	while (i + 1 < s->size_a)
	{
		s->a[i] = s->a[i + 1];
		i++;
	}
	s->size_a--;
	ft_putstr_fd("pb\n", 1);
}

/* push b->a */
void	pa(t_stack *s)
{
	int	i;

	i = s->size_a;
	while (i > 0)
	{
		s->a[i] = s->a[i - 1];
		i--;
	}
	if (s->size_b > 0)
		s->a[0] = s->b[0];
	s->size_a++;
	i = 0;
	while (i + 1 < s->size_b)
	{
		s->b[i] = s->b[i + 1];
		i++;
	}
	s->size_b--;
	ft_putstr_fd("pa\n", 1);
}
