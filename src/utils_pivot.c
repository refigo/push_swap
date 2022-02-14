/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pivot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:28:05 by mgo               #+#    #+#             */
/*   Updated: 2022/02/14 11:28:20 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*convert_stack_to_array(t_stack *stack, int size)
{
	int			*ret_array;
	t_dbly_lnkd	*tmp;
	int			i;

	ret_array = ft_calloc(size, sizeof(int));
	if (!ret_array)
		exit_error_msg("Error: malloc failed\n");
	tmp = stack->top;
	i = -1;
	while (++i < size)
	{
		ret_array[i] = tmp->num;
		tmp = tmp->next;
	}
	return (ret_array);
}

void	set_two_pivot_in_stack(int pivot[2], t_stack *stack, int size)
{
	int	*array;

	array = convert_stack_to_array(stack, size);
	set_array_quick_sorted(array, size);
	pivot[SMALL] = array[1 * size / 3];
	pivot[BIG] = array[2 * size / 3];
	free(array);
}

int	get_mid_num(t_stack *stack, int size)
{
	int	ret_mid;
	int	*tmp_array;

	tmp_array = convert_stack_to_array(stack, size);
	set_array_quick_sorted(tmp_array, size);
	ret_mid = tmp_array[size / 2];
	free(tmp_array);
	return (ret_mid);
}
