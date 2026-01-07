/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:25:50 by mchiacha          #+#    #+#             */
/*   Updated: 2026/01/07 14:25:52 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	mini_sort(t_stack *s)
{
	if (s->size_a == 2)
		sort_2(s);
	else if (s->size_a == 3)
		sort_3(s);
	else if (s->size_a == 4)
		sort_4(s);
	else if (s->size_a == 5)
		sort_5(s);
}

void	sort_2(t_stack *s)
{
	if (s->a[0] > s->a[1])
		sa(s);
}

void	sort_3(t_stack *s)
{
	int	x;
	int	y;
	int	z;

	x = s->a[0];
	y = s->a[1];
	z = s->a[2];
	if (x > y && y < z && x < z)
		sa(s);
	else if (x > y && y > z && x > z)
	{
		sa(s);
		rra(s);
	}
	else if (x > y && y < z && x > z)
		ra(s);
	else if (x < y && y > z && x < z)
	{
		sa(s);
		ra(s);
	}
	else if (x < y && y > z && x > z)
		rra(s);
}

void	sort_4(t_stack *s)
{
	push_min_to_b(s);
	sort_3(s);
	pa(s);
}

void	sort_5(t_stack *s)
{
	push_min_to_b(s);
	push_min_to_b(s);
	sort_3(s);
	pa(s);
	pa(s);
}
