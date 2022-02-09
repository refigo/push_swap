/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:43:13 by mgo               #+#    #+#             */
/*   Updated: 2022/02/09 10:35:04 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_leaks(void)
{
	system("leaks push_swap");
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

	printf("data->a_top: [%p]\n", (data->a_top));
	printf("data->a_bot: [%p]\n", (data->a_bot));
	printf("data->b_top: [%p]\n", (data->b_top));
	printf("data->b_bot: [%p]\n", (data->b_bot));

	
	printf("data->a_top->num: [%d]\n", (data->a_top->num));
	printf("data->a_bot->num: [%d]\n", (data->a_bot->num));

	printf("-- done t_push_swap\n");
}

void	test_mgo()
{
	printf("INT_MIN: [%ld]\n", INT_MIN);
	printf("INT_MAX: [%d]\n", INT_MAX);
}
