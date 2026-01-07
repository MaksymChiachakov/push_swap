/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:39:34 by mchiacha          #+#    #+#             */
/*   Updated: 2026/01/07 13:39:35 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap_first(int *arr, int len)
{
	int	tmp;

	if (len < 2)
		return ;
	tmp = arr[0];
	arr[0] = arr[1];
	arr[1] = tmp;
}

void	sa(t_stack *s)
{
	swap_first(s->a, s->size_a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *s)
{
	swap_first(s->b, s->size_b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *s)
{
	swap_first(s->a, s->size_a);
	swap_first(s->b, s->size_b);
	ft_putstr_fd("ss\n", 1);
}
