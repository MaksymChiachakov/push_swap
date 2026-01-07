/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_suite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:39:27 by mchiacha          #+#    #+#             */
/*   Updated: 2026/01/07 13:39:29 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rr(t_stack *s)
{
	ra(s);
	rb(s);
	ft_putstr_fd("rr\n", 1);
}

void	rra(t_stack *s)
{
	rotate_right(s->a, s->size_a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *s)
{
	rotate_right(s->b, s->size_b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *s)
{
	rotate_right(s->a, s->size_a);
	rotate_right(s->b, s->size_b);
	ft_putstr_fd("rrr\n", 1);
}
