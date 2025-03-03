/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:44:28 by ikozhina          #+#    #+#             */
/*   Updated: 2025/03/03 14:59:45 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sorting(t_stack *list, int length)
{
	if (length <= 5)
	{
		sort_five_or_less(list, list->capacity);
		// printf("\nsorted\n");
		// print_circular_buffer_a(list, list->capacity);
	}
	else if (length > 5 && length <= 100)
	{
		sort_hundred(list, list->capacity);
	}
	else
	{
		initial_split(list, length);
		radix_sort(list, list->capacity);
		final_merge(list, list->capacity);
	}
}

void	initial_split(t_stack *list, int length_a)
{
	int	currect_index;

	currect_index = 0;
	while (currect_index < length_a)
	{
		if(list->stack_a[list->a_start] & 1)
		{
			push_b(list, list->capacity);
		}
		else
		{
			rotate_a(list, list->capacity);
		}
		currect_index++;
	}
}
void	radix_sort(t_stack *list, int capacity)
{
	int	i;
	int	len_b;
	int	len_a;
	int	max_bits;

	i = 1;
	max_bits = count_bits(find_max_a(list, capacity));
	while (i < max_bits)
	{
		len_a = list->length_a;
		len_b = list->length_b;
		while(len_a > 0)
		{
			if ((list->stack_a[list->a_start] >> i) & 1)
			{
				push_b(list, capacity);
				len_a--;
				if (!((list->stack_a[list->a_start] >> i) & 1) && len_a > 1)
				{
					rotate_both(list, capacity);
					len_a--;
				}
				else
					rotate_b(list, capacity);
			}
			else
			{
				rotate_a(list, capacity);
				len_a--;
			}
		}
		while(len_b > 0)
		{
			if (!((list->stack_b[list->b_start] >> i) & 1))
			{
				push_a(list, capacity);
				len_b--;
				if (((list->stack_b[list->b_start] >> i) & 1) && len_b > 1)
				{
					rotate_both(list, capacity);
					len_b--;
				}
				else
					rotate_a(list, capacity);
			}
			else
			{
				rotate_b(list, capacity);
				len_b--;
			}
		}
		i++;
	}
}

void	final_merge(t_stack *list, int capacity)
{
	int	i;

	i = 0;
	int len_b = list->length_b;
	while(i < len_b)
	{
		push_a(list, capacity);
		rotate_a(list, capacity);
		i++;
	}
}
int	count_bits(int max)
{
	int	count;

	count = 0;
	while (max > 0)
	{
		count++;
		max = max >> 1;
	}
	return count;
}
