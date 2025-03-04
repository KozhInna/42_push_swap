/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:54:34 by ikozhina          #+#    #+#             */
/*   Updated: 2025/03/04 10:10:27 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swap_b(t_stack *list, int capacity)
{
	int	temp;

	if (list->b_start == list->b_end)
		return;
	temp = list->stack_b[list->b_start];
	list->stack_b[list->b_start] = list->stack_b[(list->b_start + 1) % capacity];
	list->stack_b[(list->b_start + 1) % capacity] = temp;
	write(1, "sb\n", 3);
}

void	rrotate_b(t_stack *list, int capacity)
{
	if (list->b_start == list->b_end)
		return ;
	if (list->length_b == capacity)
	{
		list->b_end = (list->b_end - 1 + capacity) % capacity;
		list->b_start = (list->b_start - 1 + capacity) % capacity;
	}
	else
	{
		list->b_start = (list->b_start - 1 + capacity) % capacity;
		list->stack_b[list->b_start] = list->stack_b[list->b_end];
		list->b_end = (list->b_end - 1 + capacity) % capacity;
	}
	write(1, "rrb\n", 4);
}
void	rotate_b(t_stack *list, int capacity)
{
	if (list->b_start == list->b_end)
		return ;
	list->b_end = (list->b_end + 1) % capacity;
	list->stack_b[list->b_end] = list->stack_b[list->b_start];
	list->b_start = (list->b_start + 1) % capacity;
	write(1, "rb\n", 3);
}
void	push_b(t_stack *list, int capacity)
{
	if (list->length_b != 0)
		list->b_start = (list->b_start - 1 + capacity) % capacity;
	list->stack_b[list->b_start] = list->stack_a[list->a_start];
	list->length_a--;
	list->length_b++;
	if (list->length_a != 0)
		list->a_start = (list->a_start + 1) % capacity;
	write(1, "pb\n", 3);
}

