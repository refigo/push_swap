/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 13:27:37 by mgo               #+#    #+#             */
/*   Updated: 2022/02/13 13:44:29 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	push_all_to_stack_a(t_push_swap *data, int size)
{
	while (size--)
		operate_cmd("pa", data);
}

static void	sort_reversely_min_unit_stack_b(t_push_swap *data, int size)
{
	if (size == 2)
		sort_reversely_stack_b_two(data);
	else if (size == 3)
		sort_reversely_stack_b_three(data);
}

static void	divide_stack_b_by_pivot_counting_cmd(t_push_swap *data, int size, \
		int pivot[2], int count[3])
{
	while (size--)
	{
		if ((data->b->top->num) < pivot[SMALL])
		{
			operate_cmd("rb", data);
			count[RB]++;
		}
		else
		{
			operate_cmd("pa", data);
			if ((data->a->top->num) < pivot[BIG])
			{
				if ((size > 0) && (data->b->top->num) < pivot[SMALL])
				{
					operate_cmd("rr", data);
					count[RB]++;
					size--;
				}
				else
					operate_cmd("ra", data);
				count[RA]++;
			}
		}
	}
}

void	sort_stack_b(t_push_swap *data, int size)
{
	int	pivot[2];
	int	count[3];

	if (is_sorted_reversely_size(data->b, size))
		return (push_all_to_stack_a(data, size));
	if (size <= 3)
	{
		sort_reversely_min_unit_stack_b(data, size);
		return (push_all_to_stack_a(data, size));
	}
	set_two_pivot_in_stack(pivot, data->b, size);
	ft_memset(count, 0, 3 * sizeof(int));
	divide_stack_b_by_pivot_counting_cmd(data, size, pivot, count);
	sort_stack_a(data, size - count[RB] - count[RA]);
	retrieve_big_nums_to_top(data, count);
	sort_stack_a(data, count[RA]);
	sort_stack_b(data, count[RB]);
}
