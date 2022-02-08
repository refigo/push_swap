/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lnkd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:44:15 by mgo               #+#    #+#             */
/*   Updated: 2022/02/08 14:59:58 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
