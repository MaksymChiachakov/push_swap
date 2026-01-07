#include "../include/push_swap.h"

/* helpers to swap first two of an array */
static void	swap_first(int *arr, int len)
{
	int	tmp;

	if (len < 2)
		return ;
	tmp = arr[0];
	arr[0] = arr[1];
	arr[1] = tmp;
}

/* sa */
void	sa(t_stack *s)
{
	swap_first(s->a, s->size_a);
	ft_putstr_fd("sa\n", 1);
}

/* sb */
void	sb(t_stack *s)
{
	swap_first(s->b, s->size_b);
	ft_putstr_fd("sb\n", 1);
}

/* ss */
void	ss(t_stack *s)
{
	swap_first(s->a, s->size_a);
	swap_first(s->b, s->size_b);
	ft_putstr_fd("ss\n", 1);
}