/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:05:46 by mgo               #+#    #+#             */
/*   Updated: 2022/02/09 14:19:17 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_push_swap *data)
{
	operate_cmd("pb", data);
	operate_cmd("pb", data);
	operate_cmd("pb", data);
	operate_cmd("pb", data);
	operate_cmd("pa", data);

	ft_putendl_fd("-----------------------After push---------------------", 1);
	ft_putendl_fd("[[data->a]]", 1);
	test_t_stack(data->a);
	ft_putendl_fd("[[data->b]]", 1);
	test_t_stack(data->b);

	operate_cmd("sa", data);
	operate_cmd("sb", data);
	operate_cmd("ss", data);

	ft_putendl_fd("-----------------------After swap---------------------", 1);
	ft_putendl_fd("[[data->a]]", 1);
	test_t_stack(data->a);
	ft_putendl_fd("[[data->b]]", 1);
	test_t_stack(data->b);

	operate_cmd("ra", data);
	operate_cmd("rb", data);
	operate_cmd("rr", data);

	ft_putendl_fd("-----------------------After rotate---------------------", 1);
	ft_putendl_fd("[[data->a]]", 1);
	test_t_stack(data->a);
	ft_putendl_fd("[[data->b]]", 1);
	test_t_stack(data->b);

	operate_cmd("rra", data);
	operate_cmd("rrb", data);
	operate_cmd("rrr", data);

	ft_putendl_fd("-----------------------After rrotate---------------------", 1);
	ft_putendl_fd("[[data->a]]", 1);
	test_t_stack(data->a);
	ft_putendl_fd("[[data->b]]", 1);
	test_t_stack(data->b);
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
