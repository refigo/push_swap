/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:05:46 by mgo               #+#    #+#             */
/*   Updated: 2022/02/09 13:05:26 by mgo              ###   ########.fr       */
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

void	sort_stack(t_push_swap *data)
{
	push_from_to((data->a), (data->b));
	push_from_to((data->a), (data->b));
	push_from_to((data->a), (data->b));

	ft_putendl_fd("-----------------------After push---------------------", 1);
	ft_putendl_fd("[[data->a]]", 1);
	test_t_stack(data->a);
	ft_putendl_fd("[[data->b]]", 1);
	test_t_stack(data->b);

	rotate_stack(data->a);
	rotate_stack(data->b);
	rotate_stack(data->a);
	rotate_stack(data->b);

	ft_putendl_fd("-----------------------After rotate---------------------", 1);
	ft_putendl_fd("[[data->a]]", 1);
	test_t_stack(data->a);
	ft_putendl_fd("[[data->b]]", 1);
	test_t_stack(data->b);

	reverse_rotate_stack(data->a);
	reverse_rotate_stack(data->b);

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
