/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:43:13 by mgo               #+#    #+#             */
/*   Updated: 2022/02/09 12:35:38 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_leaks(void)
{
	system("leaks push_swap");
}

void	test_dbly_lnkd(t_dbly_lnkd *node)
{
	t_dbly_lnkd	*tmp;

	if (!node)
		return ;

	printf("--- test_dbly_lnkd\n");		

	tmp = node;
	while (tmp)
	{
		printf("[%d]", tmp->num);
		tmp = tmp->next;
	}
	printf("\n");

	printf("---- reverse\n");
	tmp = node;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp)
	{
		printf("[%d]", tmp->num);
		tmp = tmp->prev;
	}
	printf("\n");

	printf("--- done dbly_lnkd\n");
}

void	test_t_stack(t_stack *stack)
{
	/*
	if (!(stack->top) || !(stack->bot))
		return ;
	*/
	printf("-- test_t_stack\n");

	printf("stack->top->num: [%d]\n", stack->top->num);
	printf("stack->bot->num: [%d]\n", stack->bot->num);
	test_dbly_lnkd(stack->top);

	printf("-- done_t_stack\n");
}

void	test_t_push_swap(t_push_swap *data)
{
	printf("- test_t_push_swap\n");		

	printf("data->a: [%p]\n", (data->a));
	printf("data->b: [%p]\n", (data->b));

	if ((data->a->top) && (data->a->bot))
	{
		printf("[[data->a]]\n");
		test_t_stack(data->a);
	}
	if ((data->b->top) && (data->b->bot))
	{
		printf("[[data->b]]\n");
		test_t_stack(data->b);
	}

	printf("- done t_push_swap\n");
}

void	test_mgo()
{
	printf("INT_MIN: [%ld]\n", INT_MIN);
	printf("INT_MAX: [%d]\n", INT_MAX);
}
