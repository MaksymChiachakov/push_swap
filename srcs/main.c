#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	char	**tokens;
	int		*arr;
	int		n;
	int		*indexed;
	t_stack	*s;
	int		i;
	int n_chunks;

	if (argc < 2)
		return (0);
	tokens = split_args(argc, argv);
	if (!tokens)
		return (0);
	if (!parse_integers(tokens, &arr, &n))
		return (free_tokens(tokens), 0);
	if (!check_duplicates(arr, n))
		return (free(arr), free_tokens(tokens), 0);
	/* ----------- INDEXATION ----------- */
	indexed = indexify(arr, n); // transforme arr en indices 0..n-1
	if (!indexed)
		return (free(arr), free_tokens(tokens), 0);
	s = stack_init(n);
	if (!s)
		return (free(indexed), free(arr), free_tokens(tokens), 0);
	// remplir stack A avec les indices
	for (i = 0; i < n; i++)
		s->a[i] = indexed[i];
	s->size_a = n;
	/* ------------ MINI SORT ------------ */
	if (s->size_a <= 5)
		mini_sort(s);
	else
	{
		if (s->size_a <= 100)
			n_chunks = 5; // pour 100 éléments
		else
			n_chunks = 9; // pour 500 éléments
		push_chunks_to_b(s, n_chunks);
		push_back_to_a(s);
	}
	stack_free(s);
	free(indexed);
	free(arr);
	free_tokens(tokens);
	return (0);
}
