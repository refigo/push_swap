/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:05:46 by mgo               #+#    #+#             */
/*   Updated: 2022/02/09 11:19:05 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_from_to(t_dbly_lnkd **from_stack, t_dbly_lnkd **to_stack)
{
	t_dbly_lnkd	*moving;

	if ((*from_stack) == NULL)
		return ;
	moving = *from_stack;
	*from_stack = moving->next;
	if (*from_stack)
		(*from_stack)->prev = NULL;
	if (*to_stack)
		(*to_stack)->prev = moving;
	moving->next = *to_stack;
	*to_stack = moving;
}

void	sort_stack(t_push_swap *data)
{
	push_from_to(&(data->a_top), &(data->b_top));
	push_from_to(&(data->a_top), &(data->b_top));

	test_dbly_lnkd(data->a_top);
	test_dbly_lnkd(data->b_top);
}

int	main(int argc, char **argv)
{
	t_push_swap	data;

	if (argc < 2)
		exit_error_msg("input error\n");	//todo: remove later
	set_data(&data, argv);
	sort_stack(&data);
	//clear_stack();

	//test_leaks();
	return (0);
}
