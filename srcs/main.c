#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	char	**tokens;
	int		*arr;
	int		n;
	int 	i;
	int		*indexed;
	t_stack	*s;

	i = -1;
	if (argc < 2)
		return (0);
	tokens = split_args(argc, argv);
	if (!tokens)
		return (0);
	if (!parse_integers(tokens, &arr, &n))
		return (free_tokens(tokens), 0);
	if (!check_duplicates(arr, n))
		return (free(arr), free_tokens(tokens), 0);
	indexed = indexify(arr, n);
	if (!indexed)
		return (free(arr), free_tokens(tokens), 0);
	s = stack_init(n);
	if (!s)
		return (free(indexed), free(arr), free_tokens(tokens), 0);
	while (++i < n)
		s->a[i] = indexed[i];
	s->size_a = n;

	radix_with_ops(s);

	stack_free(s);
	free(indexed);
	free(arr);
	free_tokens(tokens);
	return (0);
}