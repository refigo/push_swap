/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:43:13 by mgo               #+#    #+#             */
/*   Updated: 2022/02/07 16:47:26 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_input_arguments()
{

}

void	test_doubly_linked(t_doubly_linked *stack)
{
	t_doubly_linked	*tmp;
	char			*test;

	if (!stack)
		return ;

	printf("-- test_doubly_linked\n");		
	tmp = stack;
	while (tmp)
	{
		printf("[%s]", tmp->test);
		tmp = tmp->next;
	}
	printf("\n");

	printf("--- reverse\n");
	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp)
	{
		printf("[%s]", tmp->test);
		tmp = tmp->prev;
	}
	printf("\n");
	printf("-- done\n");
}
