/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_to_hundred.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:32:08 by ikozhina          #+#    #+#             */
/*   Updated: 2025/03/05 14:17:11 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_hundred(t_stack *list, int capacity)
{
	int	point;
	int	len_a;
	int	max;
	int	min;

	while (list->length_a > 3)
	{
		max = find_max_a(list, capacity);
		min = find_min_a(list, capacity);
		point = min + (max - min) / 3;
		len_a = list->length_a;
		while (len_a > 0)
		{
			if (list->stack_a[list->a_start] <= point)
				push_b(list, capacity);
			else
				rotate_a(list, capacity);
			len_a--;
		}
	}
	sort_three(list, capacity);
	push_nearest_max_to_a(list, capacity);
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
