#include "../include/push_swap.h"

int	find_min_pos(t_stack *s)
{
	int	pos;
	int	min;

	pos = 0;
	min = s->a[0];
	for (int i = 1; i < s->size_a; i++)
	{
		if (s->a[i] < min)
		{
			min = s->a[i];
			pos = i;
		}
	}
	return (pos);
}

void	push_min_to_b(t_stack *s)
{
	int	size;

	int pos = find_min_pos(s);
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
