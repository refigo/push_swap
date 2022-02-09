/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:05:35 by mgo               #+#    #+#             */
/*   Updated: 2022/02/09 10:33:48 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>

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
	int		num;
	void	*prev;
	void	*next;
}				t_dbly_lnkd;

typedef struct s_push_swap
{
	t_dbly_lnkd	*a_top;
	t_dbly_lnkd	*a_bot;
	t_dbly_lnkd	*b_top;
	t_dbly_lnkd	*b_bot;
}				t_push_swap;

// set_data.c
void	set_data(t_push_swap *data, char **argv);

// exit.c
void	exit_error_msg(char *msg);
void	exit_error_2msg(char *msg1, char *msg2);

// utils_lnkd.c
t_dbly_lnkd	*make_new_lnkd(int num);
void		add_new_lnkd_back(t_dbly_lnkd **stack, int num);

// test_ps.c
void	test_dbly_lnkd(t_dbly_lnkd *stack);
void	test_t_push_swap(t_push_swap *data);
void	test_leaks(void);

#endif
