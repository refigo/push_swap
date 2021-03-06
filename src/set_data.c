/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:08:09 by mgo               #+#    #+#             */
/*   Updated: 2022/02/15 16:55:30 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_num_duplicated(t_dbly_lnkd *stack, int num_being_checked)
{
	t_dbly_lnkd	*tmp;

	if (stack == NULL)
		return ;
	tmp = stack;
	while (tmp)
	{
		if (tmp->num == num_being_checked)
			exit_error_msg("Error\n");
		tmp = tmp->next;
	}
}

static int	check_sign(char *str, int *index)
{
	int	ret_flag_minus;

	ret_flag_minus = FALSE;
	if (str[*index] == '+' || str[*index] == '-')
	{
		if (str[*index] == '-')
			ret_flag_minus = TRUE;
		(*index)++;
	}
	return (ret_flag_minus);
}

static int	get_atoi_valid(char *str)
{
	long long	ret_num;
	int			flag_minus;
	int			i;

	ret_num = 0;
	i = 0;
	flag_minus = check_sign(str, &i);
	if (ft_strlen(&(str[i])) == 0)
		exit_error_msg("Error\n");
	while (ft_isdigit(str[i]))
	{
		ret_num *= 10;
		ret_num += str[i] - '0';
		i++;
	}
	if (flag_minus == TRUE)
		ret_num *= -1;
	if (str[i] != '\0' || ret_num < INT_MIN || ret_num > INT_MAX)
		exit_error_msg("Error\n");
	return ((int)ret_num);
}

static t_dbly_lnkd	*get_stack_top_with_args(char **argv)
{
	t_dbly_lnkd	*ret_stack;
	char		**splitted;
	int			num_arg;
	int			i;
	int			j;

	ret_stack = NULL;
	i = 0;
	while (argv[++i])
	{
		splitted = ft_split(argv[i], ' ');
		if (!splitted)
			exit_error_msg("Error: malloc failed\n");
		j = -1;
		while (splitted[++j])
		{
			num_arg = get_atoi_valid(splitted[j]);
			check_num_duplicated(ret_stack, num_arg);
			add_new_lnkd_back(&ret_stack, num_arg);
		}
		mgo_free_2ptr(splitted);
	}
	return (ret_stack);
}

void	set_data(t_push_swap *data, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_dbly_lnkd	*tmp;

	stack_a = ft_calloc(1, sizeof(t_stack));
	stack_b = ft_calloc(1, sizeof(t_stack));
	if (!stack_a || !stack_b)
		exit_error_msg("Error: malloc failed\n");
	data->a = stack_a;
	data->b = stack_b;
	data->a->top = get_stack_top_with_args(argv);
	tmp = data->a->top;
	while (tmp->next)
		tmp = tmp->next;
	data->a->bot = tmp;
	data->is_checker = FALSE;
}
