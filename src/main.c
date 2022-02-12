/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:05:46 by mgo               #+#    #+#             */
/*   Updated: 2022/02/12 16:27:14 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// utils_stack.c?
int	*convert_stack_to_array(t_stack *stack, int size)
{
	int			*ret_array;
	t_dbly_lnkd	*tmp;
	int			i;

	// size
	ret_array = ft_calloc(size, sizeof(int));
	if (!ret_array)
		exit_error_msg("Error: malloc failed\n");
	tmp = stack->top;
	i = -1;
	while (++i < size)
	{
		ret_array[i] = tmp->num;
		tmp = tmp->next;
	}
	return (ret_array);
}

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
	int	i;
	int	j;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		while (pivot > array[i])
			i++;
		while (pivot < array[j])
			j--;
		if (i >= j)
			break ;
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
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

// utils_stack.c?
int	get_mid_num(t_stack *stack, int size)
{
	int	ret_mid;
	int	*tmp_array;

	tmp_array = convert_stack_to_array(stack, size);
	set_array_quick_sorted(tmp_array, size);
	ret_mid = tmp_array[size / 2];
	free(tmp_array);
	return (ret_mid);
}

void	set_two_pivot(int pivot[2], t_stack *stack, int size)
{
	int	*array;

	array = convert_stack_to_array(stack, size);
	set_array_quick_sorted(array, size);

	test_view_array(array, size);

	pivot[SMALL] = array[1 * size / 3];
	pivot[BIG] = array[2 * size / 3];

	printf("pivot[SAMLL]: [%d]\n", pivot[SMALL]);
	printf("pivot[BIG]: [%d]\n", pivot[BIG]);
}

// sort_stack_a.c
void	sort_stack_a(t_push_swap *data, int size)
{
	int	pivot[2];

	if (size == 2)
		return (sort_stack_a_only_two(data));
	else if (size == 3)
		return (sort_stack_a_three(data));
	if (is_sorted_size(data->a, size))
		return ;
	set_two_pivot(pivot, data->a, size);

}

void	sort_stack(t_push_swap *data)
{
	int	size_a;

	size_a = get_stack_size(data->a);

	if (is_sorted_size(data->a, size_a))
		printf("sorted!\n");
	else
		printf("not sorted..\n");
	
	if (size_a == 2)
		sort_stack_a_only_two(data);
	else if (size_a == 3)
		sort_stack_a_only_three(data);
	else if (size_a == 5)
		sort_stack_a_only_five(data);
	else if (size_a > 3)
		sort_stack_a(data, size_a);

	test_t_stack(data->a);
}

int	main(int argc, char **argv)
{
	t_push_swap	data;

	if (argc < 2)
		return (0);
	set_data(&data, argv);
	sort_stack(&data);
	//clear_stack();

	//test_leaks();
	return (0);
}
