/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:08:06 by mgo               #+#    #+#             */
/*   Updated: 2022/02/12 15:07:51 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	operate_cmd_ra_sa_rra(t_push_swap *data)
{
	operate_cmd("ra", data);
	operate_cmd("sa", data);
	operate_cmd("rra", data);
}

static void	operate_cmd_ra_sa_rra_sa(t_push_swap *data)
{
	operate_cmd_ra_sa_rra(data);
	operate_cmd("sa", data);
}

static void	operate_cmd_sa_ra_sa_rra(t_push_swap *data)
{
	operate_cmd("sa", data);
	operate_cmd_ra_sa_rra(data);
}

static void	operate_cmd_sa_ra_sa_rra_sa(t_push_swap *data)
{
	operate_cmd_sa_ra_sa_rra(data);
	operate_cmd("sa", data);
}

void	sort_stack_a_three(t_push_swap *data)
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
		operate_cmd_ra_sa_rra(data);
	else if ((top > scnd) && (top < thrd) && (scnd < thrd))
		operate_cmd("sa", data);
	else if ((top < scnd) && (top > thrd) && (scnd > thrd))
		operate_cmd_ra_sa_rra_sa(data);
	else if ((top > scnd) && (top > thrd) && (scnd < thrd))
		operate_cmd_sa_ra_sa_rra(data);
	else if ((top > scnd) && (top > thrd) && (scnd > thrd))
		operate_cmd_sa_ra_sa_rra_sa(data);
}
