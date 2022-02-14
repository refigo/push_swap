/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:20:22 by mgo               #+#    #+#             */
/*   Updated: 2022/02/14 13:15:33 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_only_four(t_push_swap *data)
{
	int	pivot;
	int	i;

	if (is_sorted_size(data->a, 4))
		return ;
	pivot = get_mid_num(data->a, 4);
	i = -1;
	while (++i < 4)
	{
		if ((data->a->top->num) < pivot)
			operate_cmd("pb", data);
		else
			operate_cmd("ra", data);
	}
	sort_stack_only_two(data);
	sort_stack_b_recur_end_pa_all(data, 2);
}

void	sort_stack(t_push_swap *data)
{
	int	size;

	size = get_stack_size(data->a);
	if (size == 2)
		sort_stack_only_two(data);
	else if (size == 3)
		sort_stack_only_three(data);
	else if (size == 4)
		sort_stack_only_four(data);
	else if (size == 5)
		sort_stack_only_five(data);
	else if (size > 5)
		sort_stack_a_recur(data, size);
}
