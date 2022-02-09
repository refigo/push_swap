/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:16:07 by mgo               #+#    #+#             */
/*   Updated: 2022/02/09 14:17:26 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_from_to(t_stack *from_stack, t_stack *to_stack)
{
	t_dbly_lnkd	*moving;

	if ((from_stack)->top == NULL)
		return ;
	moving = (from_stack)->top;
	(from_stack)->top = moving->next;
	if ((from_stack)->top)
		(from_stack)->top->prev = NULL;
	else
		(from_stack)->bot = NULL;
	if ((to_stack)->top)
		(to_stack)->top->prev = moving;
	else
		(to_stack)->bot = moving;
	moving->next = (to_stack)->top;
	(to_stack)->top = moving;
}

void	swap_stack(t_stack *stack)
{
	t_dbly_lnkd	*tmp;

	if (stack->top == NULL || stack->top == stack->bot)
		return ;
	tmp = stack->top;
	stack->top = stack->top->next;
	tmp->prev = stack->top;
	tmp->next = stack->top->next;
	stack->top->prev = NULL;
	stack->top->next = tmp;
	if (tmp->next)
		((t_dbly_lnkd *)(tmp->next))->prev = tmp;
	else
		stack->bot = tmp;
}

void	rotate_stack(t_stack *stack)
{
	t_dbly_lnkd	*moving;

	if (stack->top == NULL || stack->top == stack->bot)
		return ;
	moving = stack->top;
	stack->top = moving->next;
	stack->top->prev = NULL;
	moving->next = NULL;
	stack->bot->next = moving;
	moving->prev = stack->bot;
	stack->bot = moving;
}

void	reverse_rotate_stack(t_stack *stack)
{
	t_dbly_lnkd	*moving;

	if (stack->top == NULL || stack->top == stack->bot)
		return ;
	moving = stack->bot;
	stack->bot = moving->prev;
	stack->bot->next = NULL;
	moving->prev = NULL;
	stack->top->prev = moving;
	moving->next = stack->top;
	stack->top = moving;
}
