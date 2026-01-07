/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:39:22 by mchiacha          #+#    #+#             */
/*   Updated: 2026/01/07 13:39:23 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_left(int *arr, int len)
{
	int	tmp;
	int	i;

	if (len < 2)
		return ;
	tmp = arr[0];
	i = 0;
	while (i + 1 < len)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[len - 1] = tmp;
}

void	rotate_right(int *arr, int len)
{
	int	tmp;
	int	i;

	if (len < 2)
		return ;
	i = len - 1;
	tmp = arr[i];
	while (i > 0)
	{
		arr[i] = arr[i - 1];
		i--;
	}
	arr[0] = tmp;
}

void	ra(t_stack *s)
{
	rotate_left(s->a, s->size_a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *s)
{
	rotate_left(s->b, s->size_b);
	ft_putstr_fd("rb\n", 1);
}
