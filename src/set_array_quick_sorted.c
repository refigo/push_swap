/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_array_quick_sorted.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:42:05 by mgo               #+#    #+#             */
/*   Updated: 2022/02/12 16:42:24 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_index_pivot(int *array, int pivot, int size)
{
	int	ret_index;

	ret_index = -1;
	while (size--)
		if (array[++ret_index] == pivot)
			break ;
	return (ret_index);
}

static void	partition_array_by_pivot(int *array, int size, int pivot)
{
	int	tmp;
	int	i_front;
	int	j_behind;

	i_front = 0;
	j_behind = size - 1;
	while (i_front < j_behind)
	{
		while (array[i_front] < pivot)
			i_front++;
		while (array[j_behind] > pivot)
			j_behind--;
		if (i_front >= j_behind)
			break ;
		tmp = array[i_front];
		array[i_front] = array[j_behind];
		array[j_behind] = tmp;
	}
}

void	set_array_quick_sorted(int *array, int size)
{
	int	pivot;
	int	index_pivot;

	pivot = array[size / 2];
	partition_array_by_pivot(array, size, pivot);
	if (size > 2)
	{
		index_pivot = get_index_pivot(array, pivot, size);
		set_array_quick_sorted(array, index_pivot);
		set_array_quick_sorted(&(array[index_pivot]), size - index_pivot);
	}
}
