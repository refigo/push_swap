/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:05:35 by mgo               #+#    #+#             */
/*   Updated: 2022/02/01 14:31:18 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# include <stdio.h>

/*
- Allowed functions

write
read
malloc
free
exit
*/

typedef struct s_doubly_linked
{
	int		num;

	char	*test;

	void	*prev;
	void	*next;
}				t_doubly_linked;

// test_ps.c
void	test_doubly_linked(t_doubly_linked *stack);

#endif
