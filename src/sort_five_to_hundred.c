/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_to_hundred.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:32:08 by ikozhina          #+#    #+#             */
/*   Updated: 2025/03/05 23:06:13 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_hundred(t_stack *list, int capacity)
{
	int	point1;
	int point2;
	int	len_a;
	int	max;
	int	min;

	while (list->length_a > 3)
	{
		max = find_max_a(list, capacity);
		min = find_min_a(list, capacity);
		point1 = min + (max - min) / 4;
		point2 = min + (max - min) / 2;
		len_a = list->length_a;
		while (len_a--)
			partitioning_stack_a(list, capacity, point1, point2);
	}
	sort_three(list, capacity);
	push_nearest_max_to_a(list, capacity);
}

void	partitioning_stack_a(t_stack *list, int capacity, int p1, int p2)
{
	if (list->stack_a[list->a_start] <= p1)
	{
		push_b(list, capacity);
		if (list->length_b > 1)
			rotate_b(list, capacity);
	}
	else if (list->stack_a[list->a_start] <= p2)
		push_b(list, capacity);
	else
		rotate_a(list, capacity);
}

void	push_nearest_max_to_a(t_stack *list, int capacity)
{
	int	i;
	int	max;

	while (list->length_b > 0)
	{
		i = 0;
		max = find_max_b(list, capacity);
		while (list->stack_b[(list->b_start + i) % capacity] != max
			&& list->stack_b[(list->b_end - i + capacity) % capacity] != max)
			i++;
		if (list->stack_b[(list->b_start + i) % capacity] == max)
		{
			while (list->stack_b[list->b_start] != max)
				rotate_b(list, capacity);
		}
		else if (list->stack_b[(list->b_end - i + capacity) % capacity] == max)
		{
			while (list->stack_b[list->b_start] != max)
				rrotate_b(list, capacity);
		}
		push_a(list, capacity);
	}
}
