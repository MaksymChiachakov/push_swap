#include "../include/push_swap.h"

t_stack	*stack_init(int n)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->a = malloc(sizeof(int) * n);
	if (!s->a)
	{
		free(s);
		return (NULL);
	}
	s->b = malloc(sizeof(int) * n);
	if (!s->b)
	{
		free(s->a);
		free(s);
		return (NULL);
	}
	s->size_a = n;
	s->size_b = 0;
	s->cap = n;
	return (s);
}

void	stack_free(t_stack *s)
{
	if (!s)
		return ;
	if (s->a)
		free(s->a);
	if (s->b)
		free(s->b);
	free(s);
}

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

/* rotate array left */
static void	rotate_left(int *arr, int len)
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

/* rotate right */
static void	rotate_right(int *arr, int len)
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

/* ra rb rr rra rrb rr */
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
void	rr(t_stack *s)
{
	rotate_left(s->a, s->size_a);
	rotate_left(s->b, s->size_b);
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
