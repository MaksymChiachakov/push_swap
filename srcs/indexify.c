/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:18:07 by mchiacha          #+#    #+#             */
/*   Updated: 2026/01/07 13:18:12 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	quick_sort_index_supp(int *indices, int *arr, int *i, int *j)
{
	int	temp;

	temp = arr[*i];
	arr[*i] = arr[*j];
	arr[*j] = temp;
	temp = indices[*i];
	indices[*i] = indices[*j];
	indices[*j] = temp;
}

static void	quick_sort_index(int *arr, int *indices, int left, int right)
{
	int	pivot;
	int	i;
	int	j;

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
			quick_sort_index_supp(indices, arr, &i, &j);
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
		return (free(res), free(copy), free(indices), NULL);
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
	return (free(copy), free(indices), res);
}
