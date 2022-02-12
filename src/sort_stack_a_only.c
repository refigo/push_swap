/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a_only_three_two.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:19:42 by mgo               #+#    #+#             */
/*   Updated: 2022/02/12 15:07:31 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_a_only_two(t_push_swap *data)
{
	t_dbly_lnkd	*top;

	top = data->a->top;
	if ((top->num) > (top->next->num))
		operate_cmd("sa", data);
}

static void	operate_cmd_sa_rra(t_push_swap *data)
{
	operate_cmd("sa", data);
	operate_cmd("rra", data);
}

static void	operate_cmd_sa_ra(t_push_swap *data)
{
	operate_cmd("sa", data);
	operate_cmd("ra", data);
}

void	sort_stack_a_only_three(t_push_swap *data)
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
		operate_cmd_sa_ra(data);
	else if ((top > scnd) && (top < thrd) && (scnd < thrd))
		operate_cmd("sa", data);
	else if ((top < scnd) && (top > thrd) && (scnd > thrd))
		operate_cmd("rra", data);
	else if ((top > scnd) && (top > thrd) && (scnd < thrd))
		operate_cmd("ra", data);
	else if ((top > scnd) && (top > thrd) && (scnd > thrd))
		operate_cmd_sa_rra(data);
}

void	sort_stack_a_only_five(t_push_swap *data)
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
	sort_stack_a_only_three(data);
	if ((data->b->top->num) < (data->b->top->next->num))
		operate_cmd("sb", data);
	operate_cmd("pa", data);
	operate_cmd("pa", data);
}
