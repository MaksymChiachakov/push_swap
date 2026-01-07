#include "../include/push_swap.h"

static void	quick_sort_index(int *arr, int *indices, int left, int right)
{
	int	pivot;
	int	i;
	int	j;
	int	temp;

	if (left >= right)
		return ;
	pivot = arr[(left + right) / 2];
	i = left;
	j = right;
	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			temp = indices[i];
			indices[i] = indices[j];
			indices[j] = temp;
			i++;
			j--;
		}
	}
	quick_sort_index(arr, indices, left, j);
	quick_sort_index(arr, indices, i, right);
}

int	*indexify(int *arr, int n)
{
	int	*res;
	int	*copy;
	int	*indices;
	int	i;

	res = malloc(sizeof(int) * n);
	if (!res)
		return (NULL);
	copy = malloc(sizeof(int) * n);
	indices = malloc(sizeof(int) * n);
	if (!copy || !indices)
	{
		free(res);
		free(copy);
		free(indices);
		return (NULL);
	}
	i = -1;
	while (++i < n)
	{
		copy[i] = arr[i];
		indices[i] = i;
	}
	quick_sort_index(copy, indices, 0, n - 1);
	i = -1;
	while (++i < n)
		res[indices[i]] = i;
	free(copy);
	free(indices);
	return (res);
}