/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:10:49 by mgo               #+#    #+#             */
/*   Updated: 2022/02/09 14:21:41 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_both_stack(t_push_swap *data)
{
	swap_stack(data->a);
	swap_stack(data->b);
}

static void	rotate_both_stack(t_push_swap *data)
{
	rotate_stack(data->a);
	rotate_stack(data->b);
}

static void	reverse_rotate_both_stack(t_push_swap *data)
{
	reverse_rotate_stack(data->a);
	reverse_rotate_stack(data->b);
}

void	operate_cmd(char *cmd, t_push_swap *data)
{
	if (ft_strncmp("pa", cmd, 2) == 0)
		push_from_to(data->b, data->a);
	else if (ft_strncmp("pb", cmd, 2) == 0)
		push_from_to(data->a, data->b);
	else if (ft_strncmp("sa", cmd, 2) == 0)
		swap_stack(data->a);
	else if (ft_strncmp("sb", cmd, 2) == 0)
		swap_stack(data->b);
	else if (ft_strncmp("ss", cmd, 2) == 0)
		swap_both_stack(data);
	else if (ft_strncmp("rra", cmd, 3) == 0)
		reverse_rotate_stack(data->a);
	else if (ft_strncmp("rrb", cmd, 3) == 0)
		reverse_rotate_stack(data->b);
	else if (ft_strncmp("rrr", cmd, 3) == 0)
		reverse_rotate_both_stack(data);
	else if (ft_strncmp("ra", cmd, 2) == 0)
		rotate_stack(data->a);
	else if (ft_strncmp("rb", cmd, 2) == 0)
		rotate_stack(data->b);
	else if (ft_strncmp("rr", cmd, 2) == 0)
		rotate_both_stack(data);
	ft_putendl_fd(cmd, 1);
}
