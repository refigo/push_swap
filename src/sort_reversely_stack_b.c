/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_reversely_stack_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:21:19 by mgo               #+#    #+#             */
/*   Updated: 2022/02/13 13:41:56 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	operate_cmd_rb_sb_rrb(t_push_swap *data)
{
	operate_cmd("rb", data);
	operate_cmd("sb", data);
	operate_cmd("rrb", data);
}

static void	operate_cmd_rb_sb_rrb_sb(t_push_swap *data)
{
	operate_cmd_rb_sb_rrb(data);
	operate_cmd("sb", data);
}

static void	operate_cmd_sb_rb_sb_rrb(t_push_swap *data)
{
	operate_cmd("sb", data);
	operate_cmd_rb_sb_rrb(data);
}

void	sort_reversely_stack_b_three(t_push_swap *data)
{
	int	top;
	int	scnd;
	int	thrd;

	if (is_sorted_reversely_size(data->b, 3))
		return ;
	top = data->b->top->num;
	scnd = data->b->top->next->num;
	thrd = data->b->top->next->next->num;
	if ((top < scnd) && (top < thrd) && (scnd < thrd))
	{
		operate_cmd_sb_rb_sb_rrb(data);
		operate_cmd("sb", data);
	}
	else if ((top < scnd) && (top < thrd) && (scnd > thrd))
		operate_cmd_sb_rb_sb_rrb(data);
	else if ((top > scnd) && (top < thrd) && (scnd < thrd))
		operate_cmd_rb_sb_rrb_sb(data);
	else if ((top < scnd) && (top > thrd) && (scnd > thrd))
		operate_cmd("sb", data);
	else if ((top > scnd) && (top > thrd) && (scnd < thrd))
		operate_cmd_rb_sb_rrb(data);
}

void	sort_reversely_stack_b_two(t_push_swap *data)
{
	t_dbly_lnkd	*top;

	top = data->b->top;
	if ((top->num) < (top->next->num))
		operate_cmd("sb", data);
}
