/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:05:46 by mgo               #+#    #+#             */
/*   Updated: 2022/02/13 11:32:44 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sort_stack_a.c
static void	sort_min_unit_stack_a(t_push_swap *data, int size)
{
	if (size == 2)
		sort_stack_a_only_two(data);
	else if (size == 3)
		sort_stack_a_three(data);
}

static void	divide_stack_a_by_pivot_counting_cmd(t_push_swap *data, int size, \
		int pivot[2], int count[3])
{
	while (size--)
	{
		if ((data->a->top->num) < pivot[BIG])
		{
			operate_cmd("pb", data);
			if ((data->b->top->num) >= pivot[SMALL])
			{
				if ((size > 0) && (data->a->top->num) >= pivot[BIG])
				{
					operate_cmd("rr", data);
					count[RA]++;
					size--;
				}
				else
					operate_cmd("rb", data);
				count[RB]++;
			}
		}
		else
		{
			operate_cmd("ra", data);
			count[RA]++;
		}
	}
}

static void	retrieve_big_nums_to_top(t_push_swap *data, int origin_count[3])
{
	int	tmp_count[3];

	ft_memcpy(tmp_count, origin_count, 3 * sizeof(int));
	while ((tmp_count[RA] > 0) || (tmp_count[RB] > 0))
	{
		if ((tmp_count[RA] > 0) && (tmp_count[RB] > 0))
		{
			operate_cmd("rrr", data);
			tmp_count[RA]--;
			tmp_count[RB]--;
		}
		else if (tmp_count[RA] > 0)
		{
			operate_cmd("rra", data);
			tmp_count[RA]--;
		}
		else if (tmp_count[RB] > 0)
		{
			operate_cmd("rrb", data);
			tmp_count[RB]--;
		}
	}
}

// sort_stack_b.c

int	is_sorted_reversely_size(t_stack *stack, int size)
{
	t_dbly_lnkd	*tmp;

	tmp = stack->top;
	while (tmp->next && (--size))
	{
		if ((tmp->num) < (tmp->next->num))
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

void	push_all_to_stack_a(t_push_swap *data, int size)
{
	while (size--)
		operate_cmd("pa", data);
}


void	sort_reversely_min_unit_stack_b(t_push_swap *data, int size)
{
	if (size == 2)
		sort_reversely_stack_b_two(data);
	else if (size == 3)
		sort_reversely_stack_b_three(data);
}

void	sort_stack_b(t_push_swap *data, int size)
{
	int	pivot[2];
	int	count[3];

	if (is_sorted_reversely_size(data->a, size))
	{
		printf("sorted reversely!\n");
		push_all_to_stack_a(data, size);
		return ;
	}
	else
		printf("not sorted reversely..\n");
	if (size <= 3)
		return (sort_reversely_min_unit_stack_b(data, size));
	set_two_pivot_in_stack(pivot, data->b, size);
	ft_memset(count, 0, 3 * sizeof(int));

	// divide_stack_b_by_pivot_counting_cmd
	divide_stack_b_by_pivot_counting_cmd(data, size, pivot, count);
}

// sort_stack_a.c
void	sort_stack_a(t_push_swap *data, int size)
{
	int	pivot[2];
	int	count[3];

	if (is_sorted_size(data->a, size))
		return ;
	if (size <= 3)
		return (sort_min_unit_stack_a(data, size));
	set_two_pivot_in_stack(pivot, data->a, size);
	ft_memset(count, 0, 3 * sizeof(int));
	divide_stack_a_by_pivot_counting_cmd(data, size, pivot, count);
	retrieve_big_nums_to_top(data, count);

	// call next sorts recursively
	sort_stack_a(data, count[RA]);

	sort_stack_b(data, count[RB]);
	sort_stack_b(data, size - count[RA] - count[RB]);	// todo: capsulize

	printf("-- done sort_stack_a\n");
}

void	sort_stack(t_push_swap *data)
{
	int	size;

	size = get_stack_size(data->a);

	if (is_sorted_size(data->a, size))
		printf("sorted!\n");
	else
		printf("not sorted..\n");
	
	if (size == 2)
		sort_stack_a_only_two(data);
	else if (size == 3)
		sort_stack_a_only_three(data);
	else if (size == 5)
		sort_stack_a_only_five(data);
	else if (size > 3)
		sort_stack_a(data, size);

	test_t_stack(data->a);
	test_t_stack(data->b);
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
