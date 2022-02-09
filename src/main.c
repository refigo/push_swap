/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:05:46 by mgo               #+#    #+#             */
/*   Updated: 2022/02/09 13:43:25 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_from_to(t_stack *from_stack, t_stack *to_stack)
{
	t_dbly_lnkd	*moving;

	if ((from_stack)->top == NULL)
		return ;
	moving = (from_stack)->top;
	(from_stack)->top = moving->next;
	if ((from_stack)->top)
		(from_stack)->top->prev = NULL;
	else
		(from_stack)->bot = NULL;
	if ((to_stack)->top)
		(to_stack)->top->prev = moving;
	else
		(to_stack)->bot = moving;
	moving->next = (to_stack)->top;
	(to_stack)->top = moving;
}

void	rotate_stack(t_stack *stack)
{
	t_dbly_lnkd	*moving;

	if (stack->top == NULL || stack->top == stack->bot)
		return ;
	moving = stack->top;
	stack->top = moving->next;
	stack->top->prev = NULL;
	moving->next = NULL;
	stack->bot->next = moving;
	moving->prev = stack->bot;
	stack->bot = moving;
}

void	reverse_rotate_stack(t_stack *stack)
{
	t_dbly_lnkd	*moving;

	if (stack->top == NULL || stack->top == stack->bot)
		return ;
	moving = stack->bot;
	stack->bot = moving->prev;
	stack->bot->next = NULL;
	moving->prev = NULL;
	stack->top->prev = moving;
	moving->next = stack->top;
	stack->top = moving;
}

void	operate_cmd(char *cmd, t_push_swap *data)
{
	if (ft_strncmp("pa", cmd, 2) == 0)
		push_from_to(data->a, data->b);
	else if (ft_strncmp("pb", cmd, 2) == 0)
		push_from_to(data->a, data->b);
	else if (ft_strncmp("rra", cmd, 3) == 0)
		reverse_rotate_stack(data->a);
	else if (ft_strncmp("rrb", cmd, 3) == 0)
		reverse_rotate_stack(data->b);
	else if (ft_strncmp("rrr", cmd, 3) == 0)
	{
		reverse_rotate_stack(data->a);
		reverse_rotate_stack(data->b);
	}
	else if (ft_strncmp("ra", cmd, 2) == 0)
		rotate_stack(data->a);
	else if (ft_strncmp("rb", cmd, 2) == 0)
		rotate_stack(data->b);
	else if (ft_strncmp("rr", cmd, 2) == 0)
	{
		rotate_stack(data->a);
		rotate_stack(data->b);
	}
	ft_putendl_fd(cmd, 1);
}

void	sort_stack(t_push_swap *data)
{
	operate_cmd("pb", data);
	operate_cmd("pb", data);
	operate_cmd("pb", data);

	ft_putendl_fd("-----------------------After push---------------------", 1);
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
