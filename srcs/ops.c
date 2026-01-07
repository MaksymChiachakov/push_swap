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
