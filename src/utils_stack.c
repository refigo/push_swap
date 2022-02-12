/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:21:50 by mgo               #+#    #+#             */
/*   Updated: 2022/02/12 18:18:10 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_stack *stack)
{
	int			ret_size;
	t_dbly_lnkd	*tmp;

	ret_size = 0;
	tmp = stack->top;
	while (tmp)
	{
		ret_size++;
		tmp = tmp->next;
	}
	return (ret_size);
}

int	is_sorted_size(t_stack *stack, int size)
{
	t_dbly_lnkd	*tmp;

	tmp = stack->top;
	while (tmp->next && (--size))
	{
		if ((tmp->num) > (tmp->next->num))
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

int	*convert_stack_to_array(t_stack *stack, int size)
{
	int			*ret_array;
	t_dbly_lnkd	*tmp;
	int			i;

	// size
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

void	set_two_pivot(int pivot[2], t_stack *stack, int size)
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
