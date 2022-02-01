/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:05:46 by mgo               #+#    #+#             */
/*   Updated: 2022/02/01 14:43:26 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_doubly_linked	*make_and_get_linked(t_doubly_linked **stack)
{
	t_doubly_linked	*current;

	if (!(*stack))
	{
		current = ft_calloc(1, sizeof(t_doubly_linked));	//todo: exception
		*stack = current;
	}
	else
	{
		current = *stack;
		while (current->next)
			current = current->next;
		current->next = ft_calloc(1, sizeof(t_doubly_linked));	//todo: exception
		((t_doubly_linked *)(current->next))->prev = current;
		current = current->next;
	}
	return (current);
}

int	get_arguments(int argc, char **argv)
{
	t_doubly_linked	*stack;
	t_doubly_linked	*tmp;
	int	i;

	stack = NULL;
	i = 0;
	while (argv[++i])
	{
		printf("argv[i]: [%s]\n", argv[i]);
		tmp = make_and_get_linked(&stack);
		//todo: exception
		tmp->test = argv[i];
	}

	test_doubly_linked(stack);
	return (i - 1);
}

int	main(int argc, char **argv)
{
	printf("hello world!\n");
	get_arguments(argc, argv);
	return (0);
}
