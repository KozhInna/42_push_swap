/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_or_less.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:19:53 by ikozhina          #+#    #+#             */
/*   Updated: 2025/03/05 12:35:19 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sort_five_or_less(t_stack *list, int capacity)
{
	if (list->length_a <= 3)
		sort_three(list, capacity);
	else
		sort_five(list, capacity);
}

void	sort_five(t_stack *list, int capacity)
{
	int	len_b;

	push_nearest_min_to_b(list, capacity);
	sort_three(list, capacity);
	len_b = list->length_b;
	while (len_b > 0)
	{
		push_a(list, capacity);
		len_b--;
	}
}
void	push_nearest_min_to_b(t_stack *list, int capacity)
{
	int i;
	int min;

	while (list->length_a > 3)
	{
		i = 0;
		min = find_min_a(list, capacity);
		while (list->stack_a[(list->a_start + i) % capacity] != min &&
			list->stack_a[(list->a_end - i + capacity) % capacity] != min)
			i++;
		if (list->stack_a[(list->a_start + i) % capacity] == min)
		{
			while (list->stack_a[list->a_start] != min)
				rotate_a(list, capacity);
		}
		else if (list->stack_a[(list->a_end - i + capacity) % capacity] == min)
		{
			while (list->stack_a[list->a_start] != min)
				rrotate_a(list, capacity);
		}
		push_b(list, capacity);
	}
}

void	sort_three(t_stack *list, int capacity)
{
	int min;
	int max;

	if (is_sorted(list, capacity))
		return ;
	min = find_min_a(list, capacity);
	max = find_max_a(list, capacity);
	if (min == list->stack_a[(list->a_start + 1) % capacity] ||
		min == list->stack_a[(list->a_start) % capacity])
	{
		if (list->stack_a[list->a_start] != max)
			swap_a(list, capacity);
	}
	else if (min == list->stack_a[list->a_end] &&
		max == list->stack_a[list->a_start])
			swap_a(list, capacity);
	if (max == list->stack_a[list->a_start])
		rotate_a(list, capacity);
	else if (max == list->stack_a[(list->a_start + 1) % capacity])
		rrotate_a(list, capacity);
}

