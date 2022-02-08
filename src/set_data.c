/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:08:09 by mgo               #+#    #+#             */
/*   Updated: 2022/02/08 14:15:27 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * "Error\n" on the standard error
 *
 * some arguments aren't integers
 * some arguments are bigger than an integer
 * there are duplicates
 */
int	get_atoi_valid(char *str)
{
	long long	ret_num;
	int			flag_minus;
	int			i;

	ret_num = 0;
	flag_minus = false;
	i = 0;
	if (str[i] == '-')
	{
		flag_minus = true;
		i++;
	}
	if (ft_strlen(&(str[i])) == 0)
		exit_error_msg("Error\n");
	while (ft_isdigit(str[i]))
	{
		ret_num *= 10;
		ret_num += str[i] - '0';
		i++;
	}
	if (flag_minus == true)
		ret_num *= -1;
	if (str[i] != '\0' || ret_num < INT_MIN || ret_num > INT_MAX)
		exit_error_msg("Error\n");
	return ((int)ret_num);
}

void	check_num_duplicated(t_dbly_lnkd *stack, int num_being_checked)
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
	return ;
}

t_dbly_lnkd	*make_new_lnkd(int num)
{
	t_dbly_lnkd	*ret_new;

	ret_new = calloc(1, sizeof(t_dbly_lnkd));
	if (!ret_new)
		exit_error_msg("Error: malloc failed\n");
	ret_new->num = num;
	return (ret_new);
}

void	add_new_lnkd_back(t_dbly_lnkd **stack, int num)
{
	t_dbly_lnkd	*new;
	t_dbly_lnkd	*tmp;

	if (*stack == NULL)
	{
		*stack = make_new_lnkd(num);
		return ;
	}
	tmp = (*stack);
	while (tmp->next)
		tmp = tmp->next;
	new = make_new_lnkd(num);
	tmp->next = new;
	new->prev = tmp;
}

t_dbly_lnkd	*get_stack_with_args(char **argv)
{
	t_dbly_lnkd	*ret_stack;
	t_dbly_lnkd	*new;
	char		**splitted;
	int			num_arg;
	int			i;
	int			j;

	ret_stack = NULL;
	i = 0;
	while (argv[++i])
	{
		splitted = ft_split(argv[i], ' ');
		//test_splitted(splitted);
		if (!splitted)
			exit_error_msg("Error: malloc failed\n");
		j = -1;
		while (splitted[++j])
		{
			num_arg = get_atoi_valid(splitted[j]);
			check_num_duplicated(ret_stack, num_arg);
			printf("num_arg: [%d]\n", num_arg);
			add_new_lnkd_back(&ret_stack, num_arg);
		}

	}

	test_dbly_lnkd(ret_stack);
	return (ret_stack);
}

void	set_data(t_push_swap *data, char **argv)
{
	ft_memset(data, 0, sizeof(t_push_swap));

	data->stack_a = get_stack_with_args(argv);

	//test_dbly_lnkd(data->stack_a);

	data->stack_b = NULL;

	test_t_push_swap(data);
}
