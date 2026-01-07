#include "../include/push_swap.h"

void	radix_with_ops(t_stack *s)
{
	int	max_bits;
	int	size;

	int max = s->size_a - 1; // après indexation
	max_bits = 0;
	while ((1 << max_bits) <= max)
		max_bits++;
	for (int i = 0; i < max_bits; i++)
	{
		size = s->size_a;
		for (int j = 0; j < size; j++)
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