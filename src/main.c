/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:05:46 by mgo               #+#    #+#             */
/*   Updated: 2022/02/08 13:53:07 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dbly_lnkd	*make_and_get_linked(t_dbly_lnkd **stack)
{
	t_dbly_lnkd	*current;

	if (!(*stack))
	{
		current = ft_calloc(1, sizeof(t_dbly_lnkd));	//todo: exception
		*stack = current;
	}
	else
	{
		current = *stack;
		while (current->next)
			current = current->next;
		current->next = ft_calloc(1, sizeof(t_dbly_lnkd));	//todo: exception
		((t_dbly_lnkd *)(current->next))->prev = current;
		current = current->next;
	}
	return (current);
}

int	get_arguments(int argc, char **argv)
{
	t_dbly_lnkd	*stack;
	t_dbly_lnkd	*tmp;
	int	i;

	stack = NULL;
	i = 0;
	while (argv[++i])
	{
		printf("argv[i]: [%s]\n", argv[i]);
		// todo: check input arguments 
		//check_argument(argv[i]);
		tmp = make_and_get_linked(&stack);
		//todo: exception
		tmp->test = argv[i];
	}

	test_dbly_lnkd(stack);
	return (i - 1);
}

int	main(int argc, char **argv)
{
	t_push_swap	data;

	if (argc < 2)
		exit_error_msg("input error\n");	//todo: remove later
	set_data(&data, argv);
	//sort stack();
	//clear_stack();
	return (0);
}
