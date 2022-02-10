/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:05:35 by mgo               #+#    #+#             */
/*   Updated: 2022/02/10 11:22:25 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>

// for test
# include <stdio.h>

/*
- Allowed functions

write
read
malloc
free
exit
*/

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef enum e_bool
{
	false,
	true
}			t_bool;

typedef struct s_dbly_lnkd
{
	int					num;
	struct s_dbly_lnkd	*prev;
	struct s_dbly_lnkd	*next;
}				t_dbly_lnkd;

typedef struct s_stack
{
	t_dbly_lnkd	*top;
	t_dbly_lnkd	*bot;
}				t_stack;

typedef struct s_push_swap
{
	t_stack	*a;
	t_stack	*b;
}				t_push_swap;

// set_data.c
void	set_data(t_push_swap *data, char **argv);

// sort_stack.c

// sort_stack_a_only_three_two.c
void	sort_stack_a_only_three(t_push_swap *data);
void	sort_stack_a_two(t_push_swap *data);

// operate_cmd.c
void	operate_cmd(char *cmd, t_push_swap *data);

// cmds.c
void	push_from_to(t_stack *from_stack, t_stack *to_stack);
void	swap_stack(t_stack *stack);
void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);

// utils_stack.c
int	get_stack_size(t_stack *stack);
int	check_sorted_size(t_stack *stack, int size);

// utils_lnkd.c
t_dbly_lnkd	*make_new_lnkd(int num);
void		add_new_lnkd_back(t_dbly_lnkd **stack, int num);

// exit.c
void	exit_error_msg(char *msg);
void	exit_error_2msg(char *msg1, char *msg2);

// test_ps.c
void	test_dbly_lnkd(t_dbly_lnkd *stack);
void	test_t_stack(t_stack *stack);
void	test_t_push_swap(t_push_swap *data);
void	test_operation_cmds(t_push_swap *data);
void	test_leaks(void);

#endif
