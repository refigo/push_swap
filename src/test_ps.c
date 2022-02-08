/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:43:13 by mgo               #+#    #+#             */
/*   Updated: 2022/02/08 14:19:23 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_new_lnkd(t_dbly_lnkd *new)
{
	printf("-- test_new_lnkd\n");

	printf("new->num: [%d]\n", new->num);

	printf("-- done new_lnkd\n");

}

void	test_dbly_lnkd(t_dbly_lnkd *stack)
{
	t_dbly_lnkd	*tmp;

	if (!stack)
		return ;

	printf("-- test_dbly_lnkd\n");		

	tmp = stack;
	while (tmp)
	{
		printf("[%d]", tmp->num);
		tmp = tmp->next;
	}
	printf("\n");

	printf("--- reverse\n");
	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp)
	{
		printf("[%d]", tmp->num);
		tmp = tmp->prev;
	}
	printf("\n");

	printf("-- done dbly_lnkd\n");
}

void	test_t_push_swap(t_push_swap *data)
{
	printf("-- test_t_push_swap\n");		

	printf("data->stack_a: [%p]\n", (data->stack_a));
	printf("data->stack_b: [%p]\n", (data->stack_b));

	printf("-- done t_push_swap\n");
}

void	test_mgo()
{
	printf("INT_MIN: [%d]\n", INT_MIN);
	printf("INT_MAX: [%d]\n", INT_MAX);
}
