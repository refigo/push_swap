/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 13:29:36 by mgo               #+#    #+#             */
/*   Updated: 2022/02/14 13:36:50 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_min_unit_stack_a(t_push_swap *data, int size)
{
	if (size == 2)
		sort_stack_only_two(data);
	else if (size == 3)
		sort_stack_a_three(data);
}

static void	divide_stack_a_by_pivot_counting_cmd(t_push_swap *data, int size, \
		int pivot[2], int count[2])
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

void	sort_stack_a_recur(t_push_swap *data, int size)
{
	int	pivot[2];
	int	count[2];

	if (is_sorted_size(data->a, size))
		return ;
	if (size <= 3)
		return (sort_min_unit_stack_a(data, size));
	set_two_pivot_in_stack(pivot, data->a, size);
	ft_memset(count, 0, 2 * sizeof(int));
	divide_stack_a_by_pivot_counting_cmd(data, size, pivot, count);
	retrieve_nums_to_top(data, count);
	sort_stack_a_recur(data, count[RA]);
	sort_stack_b_recur_end_pa_all(data, count[RB]);
	sort_stack_b_recur_end_pa_all(data, size - count[RA] - count[RB]);
}
