#include "../include/push_swap.h"

// ---------------- HELPERS -----------------

// retourne la position du max dans B
static int	find_max_pos(t_stack *s)
{
	int	pos;
	int	max;

	pos = 0;
	max = s->b[0];
	for (int i = 1; i < s->size_b; i++)
	{
		if (s->b[i] > max)
		{
			max = s->b[i];
			pos = i;
		}
	}
	return (pos);
}

// retourne la position du premier élément de A dans [min,max]
static int	find_in_chunk(t_stack *s, int min, int max)
{
	for (int i = 0; i < s->size_a; i++)
	{
		if (s->a[i] >= min && s->a[i] <= max)
			return (i);
	}
	return (-1);
}

// ---------------- PUSH CHUNKS TO B -----------------
void	push_chunks_to_b(t_stack *s, int n_chunks)
{
	int	n;
	int	min_val;
	int	max_val;
	int	pos;

	n = s->cap;
	int chunk_size = (n + n_chunks - 1) / n_chunks; // arrondi vers le haut
	for (int c = 0; c < n_chunks; c++)
	{
		min_val = c * chunk_size;
		max_val = (c + 1) * chunk_size - 1;
		if (max_val >= n)
			max_val = n - 1;
		while (1)
		{
			pos = find_in_chunk(s, min_val, max_val);
			if (pos == -1)
				break ;
			// rotation minimale pour amener l’élément en haut
			if (pos <= s->size_a / 2)
			{
				// on peut combiner avec B si nécessaire
				while (pos-- > 0)
				{
					if (s->b[0] < min_val + chunk_size / 2)
						rr(s); // rotate A et B en même temps
					else
						ra(s);
				}
			}
			else
			{
				pos = s->size_a - pos;
				while (pos-- > 0)
				{
					if (s->b[0] < min_val + chunk_size / 2)
						rrr(s); // reverse rotate A et B en même temps
					else
						rra(s);
				}
			}
			pb(s);
			// placement intelligent dans B
			if (s->b[0] < min_val + chunk_size / 2)
				rb(s);
		}
	}
}

void	push_back_to_a(t_stack *s)
{
	int	pos;

	while (s->size_b > 0)
	{
		pos = find_max_pos(s);
		if (pos <= s->size_b / 2)
		{
			while (pos-- > 0)
			{
				if (s->size_a > 1 && s->a[0] > s->a[1])
					rr(s);
				else
					rb(s);
			}
		}
		else
		{
			pos = s->size_b - pos;
			while (pos-- > 0)
			{
				if (s->size_a > 1 && s->a[0] > s->a[1])
					rrr(s); // combine A et B
				else
					rrb(s);
			}
		}
		pa(s);
	}
}
