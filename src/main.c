/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:05:46 by mgo               #+#    #+#             */
/*   Updated: 2022/02/12 18:54:19 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// divide nums by pivot with counting cmd
void	divide_nums_by_pivot_with_counting_cmd(t_push_swap *data, int pivot[2], int count[3], int size)
{
	while (size--)
	{
		if ((data->a->top->num) < pivot[BIG])
		{
			operate_cmd("pb", data);
			if ((data->b->top->num) >= pivot[SMALL])
			{
				if ((size > 0) && (data->a->top->num) >= pivot[BIG])
				{
					operate_cmd("rr", data);
					count[RA]++;
					count[RB]++;
					size--;
				}
				else
				{
					operate_cmd("rb", data);
					count[RB]++;
				}
			}
		}
		else
		{
			operate_cmd("ra", data);
			count[RA]++;
		}
	}
}

// sort_stack_a.c
void	sort_stack_a(t_push_swap *data, int size)
{
	int	pivot[2];
	int	count[3];

	if (is_sorted_size(data->a, size))
		return ;
	// sort min unit stack
	if (size <= 3)
	{
		if (size == 2)
			return (sort_stack_a_only_two(data));
		else if (size == 3)
			return (sort_stack_a_three(data));
		return ;
	}

	set_two_pivot(pivot, data->a, size);
	ft_memset(count, 0, sizeof(int) * 3);
	divide_nums_by_pivot_with_counting_cmd(data, pivot, count, size);


	printf("count[RA]: [%d]\n", count[RA]);
	printf("count[RB]: [%d]\n", count[RB]);

	int	cnt_ra = count[RA];
	int	cnt_rb = count[RB];
	// retrieve big nums to top
	while (count[RA] > 0 || count[RB] > 0)
	{
		if (count[RA] > 0 && count[RB] > 0)
		{
			operate_cmd("rrr", data);
			count[RA]--;
			count[RB]--;
		}
		else if (count[RA] > 0)
		{
			operate_cmd("rra", data);
			count[RA]--;
		}
		else if (count[RB] > 0)
		{
			operate_cmd("rrb", data);
			count[RB]--;
		}
	}

	// call next sorts
	
	if (!is_sorted_size(data->a, cnt_ra))
		sort_stack_a(data, cnt_ra);

	(void)cnt_rb;
	
	printf("-- done sort_stack_a\n");
}

void	sort_stack(t_push_swap *data)
{
	int	size;

	size = get_stack_size(data->a);

	if (is_sorted_size(data->a, size))
		printf("sorted!\n");
	else
		printf("not sorted..\n");
	
	if (size == 2)
		sort_stack_a_only_two(data);
	else if (size == 3)
		sort_stack_a_only_three(data);
	else if (size == 5)
		sort_stack_a_only_five(data);
	else if (size > 3)
		sort_stack_a(data, size);

	test_t_stack(data->a);
	test_t_stack(data->b);
}

int	main(int argc, char **argv)
{
	t_push_swap	data;

	if (argc < 2)
		return (0);
	set_data(&data, argv);
	sort_stack(&data);
	//clear_stack();

	//test_leaks();
	return (0);
}
