/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:05:46 by mgo               #+#    #+#             */
/*   Updated: 2022/02/10 10:13:09 by mgo              ###   ########.fr       */
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
	printf("ret_size: [%d]\n", ret_size);
	return (ret_size);
}

int	check_sorted_size(t_stack *stack, int size)
{
	t_dbly_lnkd	*tmp;

	tmp = stack->top;
	while (tmp->next && (--size))
	{
		if ((tmp->num) > (tmp->next->num))
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

void	sort_stack(t_push_swap *data)
{
	if (check_sorted_size(data->a, get_stack_size(data->a)))
		printf("sorted!\n");
	else
		printf("not sorted..\n");
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
