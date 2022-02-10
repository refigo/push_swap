/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:05:46 by mgo               #+#    #+#             */
/*   Updated: 2022/02/10 11:19:29 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_push_swap *data)
{
	if (check_sorted_size(data->a, get_stack_size(data->a)))
		printf("sorted!\n");
	else
		printf("not sorted..\n");
	
	if (get_stack_size(data->a) == 2)
		sort_stack_a_two(data);
	
	if (get_stack_size(data->a) == 3)
		sort_stack_a_only_three(data);

	test_t_stack(data->a);
}

int	main(int argc, char **argv)
{
	t_push_swap	data;

	if (argc < 2)
		return (0);
	set_data(&data, argv);
	sort_stack(&data);
	//clear_stack();

	//test_leaks();
	return (0);
}
