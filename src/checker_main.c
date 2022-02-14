/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:37:31 by mgo               #+#    #+#             */
/*   Updated: 2022/02/14 16:10:46 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// for test
#include <stdio.h>

void	test_view_t_list(t_list *to_view)
{
	t_list	*tmp;
	char	*tmp_cont;
	int		i;

	tmp = to_view;
	i = 0;
	while (tmp)
	{
		tmp_cont = tmp->content;
		printf("list_cont[%d]: [%s]\n", i, tmp_cont);
		tmp = tmp->next;
		i++;
	}
}

void	get_and_set_instructions(t_list **instructions)
{
	t_list	*each_inst;
	char	*each_line;

	*instructions = NULL;
	each_line = NULL;
	while (get_next_line(0, &each_line) && (each_line != NULL))
	{
		each_inst = ft_lstnew(each_line);
		ft_lstadd_back(instructions, each_inst);
		each_line = NULL;
	}
	test_view_t_list(*instructions);
}

int	main(int argc, char **argv)
{
	t_push_swap	data;
	t_list		*instructions;

	printf("checker: hello world\n");

	if (argc < 2)
		exit(0);
	set_data(&data, argv);
	get_and_set_instructions(&instructions);
	// check_instructions_sorting
	// clear_data
	// clear_instructions
	system("leaks checker_bonus");
	return (0);
}
