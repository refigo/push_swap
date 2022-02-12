/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:21:50 by mgo               #+#    #+#             */
/*   Updated: 2022/02/12 15:45:38 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_stack *stack)
{
	int			ret_size;
	t_dbly_lnkd	*tmp;

	ret_size = 0;
	tmp = stack->top;
	while (tmp)
	{
		ret_size++;
		tmp = tmp->next;
	}
	return (ret_size);
}

int	is_sorted_size(t_stack *stack, int size)
{
	t_dbly_lnkd	*tmp;

	tmp = stack->top;
	while (tmp->next && (--size))
	{
		if ((tmp->num) > (tmp->next->num))
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}
