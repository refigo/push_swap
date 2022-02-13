/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:05:46 by mgo               #+#    #+#             */
/*   Updated: 2022/02/13 13:32:52 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_push_swap *data)
{
	int	size;

	size = get_stack_size(data->a);
	if (size == 2)
		sort_stack_a_only_two(data);
	else if (size == 3)
		sort_stack_a_only_three(data);
	else if (size == 5)
		sort_stack_a_only_five(data);
	else if (size > 3)
		sort_stack_a(data, size);
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
