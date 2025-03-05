/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_or_less.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:19:53 by ikozhina          #+#    #+#             */
/*   Updated: 2025/03/05 10:22:55 by ikozhina         ###   ########.fr       */
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
	int	min;
	int	i;
	int	len_b;

	i = 0;
	while (list->length_a > 3)
	{
		min = find_min_a(list, capacity);
		if (list->stack_a[(list->a_start + i) % capacity] == min)
		{
			while (list->stack_a[list->a_start] != min)
				rotate_a(list, capacity);
			push_b(list, capacity);
			i = 0;
		}
		else if (list->stack_a[(list->a_end - i + capacity) % capacity] == min)
		{
			while (list->stack_a[list->a_start] != min)
				rrotate_a(list, capacity);
			push_b(list, capacity);
			i = 0;
		}
		else
			i++;
	}
	sort_three(list, capacity);
	len_b = list->length_b;
	while (len_b > 0)
	{
		push_a(list, capacity);
		len_b--;
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


void	sort_hundred(t_stack *list, int capacity)
{
	int	point;
	int	i;
	int	len_a;
	int	max;

	while (list->length_a > 3)
	{
		point = find_min_a(list, capacity) + (find_max_a(list, capacity) - find_min_a(list, capacity)) / 3;
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
	i = 0;
	while (list->length_b > 0)
	{
		max = find_max_b(list, capacity);
		if (list->stack_b[(list->b_start + i) % capacity] == max)
		{
			while (list->stack_b[list->b_start] != max)
				rotate_b(list, capacity);
			push_a(list, capacity);
			i = 0;
		}
		else if (list->stack_b[(list->a_end - i + capacity) % capacity] == max)
		{
			while (list->stack_b[list->b_start] != max)
				rrotate_b(list, capacity);
			push_a(list, capacity);
			i = 0;
		}
		else
			i++;
	}
}
