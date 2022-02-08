/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:11:12 by mgo               #+#    #+#             */
/*   Updated: 2022/02/08 13:11:55 by mgo              ###   ########.fr       */
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
