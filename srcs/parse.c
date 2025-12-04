#include "../include/push_swap.h"

/*
** count words in a string separated by spaces
*/
static int	count_words(const char *s)
{
	int	in;
	int	i;

	in = 0;
	i = 0;
	while (s && *s)
	{
		if (*s != ' ' && in == 0)
		{
			in = 1;
			i++;
		}
		else if (*s == ' ')
			in = 0;
		s++;
	}
	return (i);
}

/*
** split_str: returns NULL-terminated array of words
** robust: frees allocated memory on error
*/
char	**split_str(const char *s)
{
	int			words;
	char		**res;
	int			i;
	int			j;
	const char	*p;
	int			len;

	words = count_words(s);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	i = 0;
	p = s;
	while (i < words)
	{
		while (*p == ' ')
			p++;
		j = 0;
		while (p[j] && p[j] != ' ')
			j++;
		res[i] = malloc(j + 1);
		if (!res[i])
		{
			while (--i >= 0)
				free(res[i]);
			free(res);
			return (NULL);
		}
		len = 0;
		while (len < j)
		{
			res[i][len] = p[len];
			len++;
		}
		res[i][len] = '\0';
		p += j;
		i++;
	}
	res[words] = NULL;
	return (res);
}

/*
** split_args: flatten argv (support "1 2 3" tokens)
** robust: frees partial allocations on failure
*/
char	**split_args(int argc, char **argv)
{
	char	**all;
	char	**tmp;
	int		total;
	int		i;
	int		j;

	all = NULL;
	total = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) == 0)
		{
			i++;
			continue ;
		}
		tmp = split_str(argv[i]);
		if (!tmp)
		{
			free_tokens(all);
			return (NULL);
		}
		j = 0;
		while (tmp[j])
			j++;
		all = realloc(all, sizeof(char *) * (total + j + 1));
		if (!all)
		{
			free_tokens(tmp);
			free_tokens(all);
			return (NULL);
		}
		j = 0;
		while (tmp[j])
			all[total++] = tmp[j++];
		free(tmp);
		i++;
	}
	if (all)
		all[total] = NULL;
	return (all);
}
