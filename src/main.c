/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:05:46 by mgo               #+#    #+#             */
/*   Updated: 2022/02/08 13:00:48 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error_msg(char *msg)
{
	if (msg)
		ft_putstr_fd(msg, 2);
	exit(1);
}

void	exit_error_2msg(char *msg1, char *msg2)
{
	if (msg1)
		ft_putstr_fd(msg1, 2);
	if (msg2)
		ft_putstr_fd(msg2, 2);
	exit(1);
}

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

int	check_argument(char *arg)
{
	// check whitespace
	
	// check digits
	return (1);
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
		check_argument(argv[i]);
		tmp = make_and_get_linked(&stack);
		//todo: exception
		tmp->test = argv[i];
	}

	test_dbly_lnkd(stack);
	return (i - 1);
}

/*
 * "Error\n" on the standard error
 *
 * some arguments aren't integers
 * some arguments are bigger than an integer
 * there are duplicates
 */
int	check_valid_and_get_atoi(char *str)
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
			exit_error_msg("malloc failed\n");
		j = -1;
		while (splitted[++j])
		{
			num_arg = check_valid_and_get_atoi(splitted[j]);
			printf("num_arg: [%d]\n", num_arg);
			//test_new_lnkd(new);
			//add stack
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

int	main(int argc, char **argv)
{
	t_push_swap	data;

	if (argc < 2)
		exit_error_msg("input error\n");
	set_data(&data, argv);
	//sort stack();
	//clear_stack();
	return (0);
}
