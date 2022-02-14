/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:18:37 by mgo               #+#    #+#             */
/*   Updated: 2022/02/14 11:19:26 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_stack(t_stack *stack)
{
	t_dbly_lnkd	*moving;
	t_dbly_lnkd	*to_free;

	moving = stack->top;
	while (moving)
	{
		to_free = moving;
		moving = moving->next;
		free(to_free);
	}
	stack->top = NULL;
	stack->bot = NULL;
}

void	clear_data(t_push_swap *data)
{
	clear_stack(data->a);
	clear_stack(data->b);
	free(data->a);
	free(data->b);
}
