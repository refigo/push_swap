/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:10:49 by mgo               #+#    #+#             */
/*   Updated: 2022/02/15 13:22:42 by mgo              ###   ########.fr       */
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
	if (ft_strncmp("pa", cmd, 2) == 0)
		*activation = push_from_to(data->b, data->a);
	else if (ft_strncmp("pb", cmd, 2) == 0)
		*activation = push_from_to(data->a, data->b);
	else if (ft_strncmp("sa", cmd, 2) == 0)
		*activation = swap_stack(data->a);
	else if (ft_strncmp("sb", cmd, 2) == 0)
		*activation = swap_stack(data->b);
	else if (ft_strncmp("ss", cmd, 2) == 0)
		*activation = swap_both_stack(data);
	else if (ft_strncmp("rra", cmd, 3) == 0)
		*activation = reverse_rotate_stack(data->a);
	else if (ft_strncmp("rrb", cmd, 3) == 0)
		*activation = reverse_rotate_stack(data->b);
	else if (ft_strncmp("rrr", cmd, 3) == 0)
		*activation = reverse_rotate_both_stack(data);
	else if (ft_strncmp("ra", cmd, 2) == 0)
		*activation = rotate_stack(data->a);
	else if (ft_strncmp("rb", cmd, 2) == 0)
		*activation = rotate_stack(data->b);
	else if (ft_strncmp("rr", cmd, 2) == 0)
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
