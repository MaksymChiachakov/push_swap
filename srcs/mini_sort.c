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
	push_min_to_b(s); // pousse le plus petit vers b
	sort_3(s);        // tri le reste
	pa(s);            // ramène le minimum
}

void	sort_5(t_stack *s)
{
	push_min_to_b(s); // pousse le plus petit vers b
	push_min_to_b(s); // pousse le 2ème plus petit vers b
	sort_3(s);        // tri les 3 restants
	pa(s);            // ramène 2ème min
	pa(s);            // ramène 1er min
}
