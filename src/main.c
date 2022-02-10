/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:05:46 by mgo               #+#    #+#             */
/*   Updated: 2022/02/10 15:21:00 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	get_index_pivot(int *array, int pivot)
{
	int	ret_index;

	ret_index = -1;
	while (array[++ret_index])
		if (array[ret_index] == pivot)
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
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
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
		index_pivot = get_index_pivot(array, pivot);
		set_array_quick_sorted(array, index_pivot);
		set_array_quick_sorted(&(array[index_pivot]), size - index_pivot);
	}
}

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

void	sort_stack_a_only_five(t_push_swap *data)
{
	int	pivot;
	int	i;

	if (check_sorted_size(data->a, 5))
		return ;
	pivot = get_mid_num(data->a, 5);
	i = -1;
	while (++i < 5)
	{
		if ((data->a->top->num) < pivot)
			operate_cmd("pb", data);
		else
			operate_cmd("ra", data);
	}
	sort_stack_a_only_three(data);
	if ((data->b->top->num) < (data->b->top->next->num))
		operate_cmd("sb", data);
	operate_cmd("pa", data);
	operate_cmd("pa", data);
}

void	sort_stack_a(t_push_swap *data)
{
	int	pivot;

	pivot = get_mid_num(data->a, get_stack_size(data->a));

}

void	sort_stack(t_push_swap *data)
{
	int	size_a;

	size_a = get_stack_size(data->a);
	if (check_sorted_size(data->a, size_a))
		printf("sorted!\n");
	else
		printf("not sorted..\n");
	
	if (size_a == 2)
		sort_stack_a_two(data);
	else if (size_a == 3)
		sort_stack_a_only_three(data);
	else if (size_a == 5)
		sort_stack_a_only_five(data);
	else if (size_a > 3)
		sort_stack_a(data);

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
