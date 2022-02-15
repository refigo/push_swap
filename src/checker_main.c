/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:37:31 by mgo               #+#    #+#             */
/*   Updated: 2022/02/15 14:45:30 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	mgo_strcmp(const char *s1, const char *s2)
{
	unsigned char	*uc_s1;
	unsigned char	*uc_s2;
	int				i;

	uc_s1 = (unsigned char *)s1;
	uc_s2 = (unsigned char *)s2;
	i = 0;
	while (uc_s1[i] || uc_s2[i])
	{
		if (uc_s1[i] != uc_s2[i])
			return (uc_s1[i] - uc_s2[i]);
		i++;
	}
	return (0);
}

static int	is_right_instruction(char *inst)
{
	if ((mgo_strcmp("pa", inst) == 0) || \
			(mgo_strcmp("pb", inst) == 0) || \
			(mgo_strcmp("sa", inst) == 0) || \
			(mgo_strcmp("sb", inst) == 0) || \
			(mgo_strcmp("ss", inst) == 0) || \
			(mgo_strcmp("rra", inst) == 0) || \
			(mgo_strcmp("rrb", inst) == 0) || \
			(mgo_strcmp("rrr", inst) == 0) || \
			(mgo_strcmp("ra", inst) == 0) || \
			(mgo_strcmp("rb", inst) == 0) || \
			(mgo_strcmp("rr", inst) == 0))
		return (TRUE);
	else
		return (FALSE);
}

static void	get_and_set_instructions(t_list **instructions)
{
	t_list	*each_inst;
	char	*each_line;
	int		status_gnl;

	*instructions = NULL;
	status_gnl = get_next_line(0, &each_line);
	while (status_gnl)
	{
		if (!is_right_instruction(each_line))
			exit_error_msg("Error\n");
		each_inst = ft_lstnew(each_line);
		ft_lstadd_back(instructions, each_inst);
		status_gnl = get_next_line(0, &each_line);
	}
	free(each_line);
}

static void	check_instructions_sorting(t_push_swap *data, t_list *instructions)
{
	t_list	*current;

	data->is_checker = TRUE;
	current = instructions;
	while (current)
	{
		operate_cmd(current->content, data);
		current = current->next;
	}
	if (is_sorted_size(data->a, get_stack_size(data->a)) \
			&& get_stack_size(data->b) == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

static void	clear_instructions(t_list **instructions)
{
	t_list	*tmp;

	while ((*instructions))
	{
		free((*instructions)->content);
		tmp = (*instructions)->next;
		free(*instructions);
		(*instructions) = tmp;
	}
}

int	main(int argc, char **argv)
{
	t_push_swap	data;
	t_list		*instructions;

	if (argc < 2)
		exit(0);
	set_data(&data, argv);
	get_and_set_instructions(&instructions);
	check_instructions_sorting(&data, instructions);
	clear_data(&data);
	clear_instructions(&instructions);
	return (0);
}
