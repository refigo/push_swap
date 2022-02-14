/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:37:31 by mgo               #+#    #+#             */
/*   Updated: 2022/02/14 16:31:02 by mgo              ###   ########.fr       */
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
// test endline

int	is_right_instruction(char *inst)
{
	if ((ft_strncmp("pa", inst, 2) == 0) || \
			(ft_strncmp("pb", inst, 2) == 0) || \
			(ft_strncmp("sa", inst, 2) == 0) || \
			(ft_strncmp("sb", inst, 2) == 0) || \
			(ft_strncmp("ss", inst, 2) == 0) || \
			(ft_strncmp("rra", inst, 3) == 0) || \
			(ft_strncmp("rrb", inst, 3) == 0) || \
			(ft_strncmp("rrr", inst, 3) == 0) || \
			(ft_strncmp("ra", inst, 2) == 0) || \
			(ft_strncmp("rb", inst, 2) == 0) || \
			(ft_strncmp("rr", inst, 2) == 0))
		return (TRUE);
	else
		return (FALSE);
}

void	get_and_set_instructions(t_list **instructions)
{
	t_list	*each_inst;
	char	*each_line;

	*instructions = NULL;
	each_line = NULL;
	while (get_next_line(0, &each_line) && (each_line != NULL))
	{
		if (!is_right_instruction(each_line))
			exit_error_msg("Error\n");
		each_inst = ft_lstnew(each_line);
		ft_lstadd_back(instructions, each_inst);
		each_line = NULL;
	}
	test_view_t_list(*instructions);
}

int		operate_instruction(t_push_swap *data, char *inst)
{
	if (is_right_instruction(inst))
	{
		operate_cmd(inst, data);
		return (TRUE);
	}
	else
		return (FALSE);

}

void	check_sorting_instructions(t_push_swap *data, t_list *instructions)
{
	t_list	*current;
	int		status_inst;

	current = instructions;
	while (current)
	{
		status_inst = operate_instruction(data, current->content);
		if (status_inst == FALSE)
			exit_error_msg("KO\n");
		current = current->next;
	}
	ft_putendl_fd("OK\n", 1);
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
	check_sorting_instructions(&data, instructions);
	// clear_data
	// clear_instructions
	//system("leaks checker_bonus");
	return (0);
}
