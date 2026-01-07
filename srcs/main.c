/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:20:03 by mchiacha          #+#    #+#             */
/*   Updated: 2026/01/07 14:20:05 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_all(t_stack *s, int *indexed, int *arr, char **tokens)
{
	stack_free(s);
	free(indexed);
	free(arr);
	free_tokens(tokens);
}

void	main_supp(t_stack *s, int *n, int *indexed)
{
	int	i;

	i = 0;
	while (i < *n)
	{
		s->a[i] = indexed[i];
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	**tokens;
	int		*arr;
	int		n;
	int		*indexed;
	t_stack	*s;

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
	main_supp(s, &n, indexed);
	s->size_a = n;
	return (radix_with_ops(s), free_all(s, indexed, arr, tokens), 0);
}
/* 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int  is_duplicate(int *arr, int n, int value)
{
    int i;

    i = 0;
    while (i < n)
    {
        if (arr[i] == value)
            return (1);
        i++;
    }
    return (0);
}

static int  generate_unique(int *arr, int n)
{
    int value;
    int mod;

    mod = 100000;
    value = rand() % mod;
    while (is_duplicate(arr, n, value))
        value = rand() % mod;
    return (value);
}

int main(void)
{
    int arr[500];
    int i;
    int value;

    i = 0;
    srand(time(NULL));

    while (i < 500)
    {
        value = generate_unique(arr, i);
        arr[i] = value;
        i++;
    }
    i = 0;

    while (i < 500)
    {
        printf("%d", arr[i]);
        if (i < 499)
            printf(" ");
        i++;
    }
    return (0);
}
*/