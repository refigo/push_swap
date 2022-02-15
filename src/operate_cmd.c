/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:10:49 by mgo               #+#    #+#             */
/*   Updated: 2022/02/15 14:49:09 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_both_stack(t_push_swap *data)
{
	swap_stack(data->a);
	swap_stack(data->b);
	return (ACT);
}

static int	rotate_both_stack(t_push_swap *data)
{
	rotate_stack(data->a);
	rotate_stack(data->b);
	return (ACT);
}

static int	reverse_rotate_both_stack(t_push_swap *data)
{
	reverse_rotate_stack(data->a);
	reverse_rotate_stack(data->b);
	return (ACT);
}

void	move_cmd_gate_and_set_activation(char *cmd, t_push_swap *data, \
		int *activation)
{
	if (mgo_strcmp("pa", cmd) == 0)
		*activation = push_from_to(data->b, data->a);
	else if (mgo_strcmp("pb", cmd) == 0)
		*activation = push_from_to(data->a, data->b);
	else if (mgo_strcmp("sa", cmd) == 0)
		*activation = swap_stack(data->a);
	else if (mgo_strcmp("sb", cmd) == 0)
		*activation = swap_stack(data->b);
	else if (mgo_strcmp("ss", cmd) == 0)
		*activation = swap_both_stack(data);
	else if (mgo_strcmp("rra", cmd) == 0)
		*activation = reverse_rotate_stack(data->a);
	else if (mgo_strcmp("rrb", cmd) == 0)
		*activation = reverse_rotate_stack(data->b);
	else if (mgo_strcmp("rrr", cmd) == 0)
		*activation = reverse_rotate_both_stack(data);
	else if (mgo_strcmp("ra", cmd) == 0)
		*activation = rotate_stack(data->a);
	else if (mgo_strcmp("rb", cmd) == 0)
		*activation = rotate_stack(data->b);
	else if (mgo_strcmp("rr", cmd) == 0)
		*activation = rotate_both_stack(data);
}

void	operate_cmd(char *cmd, t_push_swap *data)
{
	int	activation;

	activation = DEACT;
	move_cmd_gate_and_set_activation(cmd, data, &activation);
	if ((activation == ACT) && (data->is_checker == FALSE))
		ft_putendl_fd(cmd, 1);
}
