/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a_only_three_two.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:19:42 by mgo               #+#    #+#             */
/*   Updated: 2022/02/10 11:19:51 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_dbly_lnkd	*top;
	t_dbly_lnkd	*bot;

	if (check_sorted_size(data->a, 3))
		return ;
	top = data->a->top;
	bot = data->a->bot;
	if ((top->num) > (top->next->num) && (top->num) < (bot->num) \
			&& (top->next->num) < (bot->num))
		operate_cmd("sa", data);
	else if ((top->num) < (top->next->num) && (top->num) > (bot->num) \
			&& (top->next->num) > (bot->num))
		operate_cmd("rra", data);
	else if ((top->num) > (top->next->num) && (top->num) > (bot->num) \
			&& (top->next->num) < (bot->num))
		operate_cmd("ra", data);
	else if ((top->num) > (top->next->num) && (top->num) > (bot->num) \
			&& (top->next->num) > (bot->num))
		operate_cmd_sa_rra(data);
	else if ((top->num) < (top->next->num) && (top->num) < (bot->num) \
			&& (top->next->num) > (bot->num))
		operate_cmd_sa_ra(data);
}

void	sort_stack_a_two(t_push_swap *data)
{
	t_dbly_lnkd	*top;

	top = data->a->top;
	if ((top->num) > (top->next->num))
		operate_cmd("sa", data);
}
