/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_only.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:20:23 by mgo               #+#    #+#             */
/*   Updated: 2022/02/14 13:20:30 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_only_two(t_push_swap *data)
{
	t_dbly_lnkd	*top;

	top = data->a->top;
	if ((top->num) > (top->next->num))
		operate_cmd("sa", data);
}

void	sort_stack_only_three(t_push_swap *data)
{
	int	top;
	int	scnd;
	int	thrd;

	if (is_sorted_size(data->a, 3))
		return ;
	top = data->a->top->num;
	scnd = data->a->top->next->num;
	thrd = data->a->top->next->next->num;
	if ((top < scnd) && (top < thrd) && (scnd > thrd))
	{
		operate_cmd("sa", data);
		operate_cmd("ra", data);
	}
	else if ((top > scnd) && (top < thrd) && (scnd < thrd))
		operate_cmd("sa", data);
	else if ((top < scnd) && (top > thrd) && (scnd > thrd))
		operate_cmd("rra", data);
	else if ((top > scnd) && (top > thrd) && (scnd < thrd))
		operate_cmd("ra", data);
	else if ((top > scnd) && (top > thrd) && (scnd > thrd))
	{
		operate_cmd("sa", data);
		operate_cmd("rra", data);
	}
}

void	sort_stack_only_five(t_push_swap *data)
{
	int	pivot;
	int	i;

	if (is_sorted_size(data->a, 5))
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
	sort_stack_only_three(data);
	if ((data->b->top->num) < (data->b->top->next->num))
		operate_cmd("sb", data);
	operate_cmd("pa", data);
	operate_cmd("pa", data);
}
