/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_nums_to_top.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:48:26 by mgo               #+#    #+#             */
/*   Updated: 2022/02/14 11:48:44 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	retrieve_nums_to_top(t_push_swap *data, int origin_count[3])
{
	int	tmp_count[3];

	ft_memcpy(tmp_count, origin_count, 3 * sizeof(int));
	while ((tmp_count[RA] > 0) || (tmp_count[RB] > 0))
	{
		if ((tmp_count[RA] > 0) && (tmp_count[RB] > 0))
		{
			operate_cmd("rrr", data);
			tmp_count[RA]--;
			tmp_count[RB]--;
		}
		else if (tmp_count[RA] > 0)
		{
			operate_cmd("rra", data);
			tmp_count[RA]--;
		}
		else if (tmp_count[RB] > 0)
		{
			operate_cmd("rrb", data);
			tmp_count[RB]--;
		}
	}
}
