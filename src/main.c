/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:05:46 by mgo               #+#    #+#             */
/*   Updated: 2022/02/10 11:58:35 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	operate_cmd_ra_sa_rra(t_push_swap *data)
{
	operate_cmd("ra", data);
	operate_cmd("sa", data);
	operate_cmd("rra", data);
}

static void	operate_cmd_ra_sa_rra_sa(t_push_swap *data)
{
	operate_cmd_ra_sa_rra(data);
	operate_cmd("sa", data);
}

static void	operate_cmd_sa_ra_sa_rra(t_push_swap *data)
{
	operate_cmd("sa", data);
	operate_cmd_ra_sa_rra(data);
}

static void	operate_cmd_sa_ra_sa_rra_sa(t_push_swap *data)
{
	operate_cmd_sa_ra_sa_rra(data);
	operate_cmd("sa", data);
}

void	sort_stack_a_three(t_push_swap *data)
{
	int	top;
	int	scnd;
	int	thrd;

	if (check_sorted_size(data->a, 3))
		return ;
	top = data->a->top->num;
	scnd = data->a->top->next->num;
	thrd = data->a->top->next->next->num;
	if ((top < scnd) && (top < thrd) && (scnd > thrd))
		operate_cmd_ra_sa_rra(data);
	else if ((top > scnd) && (top < thrd) && (scnd < thrd))
		operate_cmd("sa", data);
	else if ((top < scnd) && (top > thrd) && (scnd > thrd))
		operate_cmd_ra_sa_rra_sa(data);
	else if ((top > scnd) && (top > thrd) && (scnd < thrd))
		operate_cmd_sa_ra_sa_rra(data);
	else if ((top > scnd) && (top > thrd) && (scnd > thrd))
		operate_cmd_sa_ra_sa_rra_sa(data);
}

void	sort_stack(t_push_swap *data)
{
	int	size_a;

	size_a = get_stack_size(data->a);
	if (check_sorted_size(data->a, size_a))
		printf("sorted!\n");
	else
		printf("not sorted..\n");
	
	if (size_a == 2)
		sort_stack_a_two(data);
	else if (size_a == 3)
		sort_stack_a_only_three(data);
	else if (size_a > 3)
		sort_stack_a_three(data);

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
