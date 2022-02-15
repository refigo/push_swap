/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:20:22 by mgo               #+#    #+#             */
/*   Updated: 2022/02/15 16:58:35 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
