#include "../include/push_swap.h"

int	*indexify(int *arr, int n)
{
	int	*res;
	int	i;
	int	j;
	int	rank;

	res = malloc(sizeof(int) * n);
	if (!res)
		return (NULL);
	i = 0;
	while (i < n)
	{
		rank = 0;
		j = 0;
		while (j < n)
		{
			if (arr[j] < arr[i])
				rank++;
			j++;
		}
		res[i] = rank;
		i++;
	}
	return (res);
}
