/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:18:09 by ikozhina          #+#    #+#             */
/*   Updated: 2025/02/25 09:01:05 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

// void	swap_a(t_stack *list, int capacity)
// {
// 	int	temp;

// 	if (list->a_start == list->a_end)
// 		return;
// 	temp = list->stack_a[list->a_start];
// 	list->stack_a[list->a_start] = list->stack_a[(list->a_start + 1) % capacity];
// 	list->stack_a[(list->a_start + 1) % capacity] = temp;
// 	// write(1, "sa\n", 3);
// }

void	rotate_a(t_stack *list, int capacity)
{
	if (list->a_start == list->a_end)
		return ;
	list->a_end = (list->a_end + 1) % capacity;
	list->stack_a[list->a_end] = list->stack_a[list->a_start];
	list->a_start = (list->a_start + 1) % capacity;
	// write(1, "ra\n", 3);
}
void	rotate_b(t_stack *list, int capacity)
{
	if (list->b_start == list->b_end)
		return ;
	list->b_end = (list->b_end + 1) % capacity;
	list->stack_b[list->b_end] = list->stack_b[list->b_start];
	list->b_start = (list->b_start + 1) % capacity;
	// write(1, "rb\n", 3);
}
void	push_b(t_stack *list, int capacity)
{
	list->b_start = (list->b_start - 1 + capacity) % capacity;
	list->stack_b[list->b_start] = list->stack_a[list->a_start];
	list->a_start = (list->a_start + 1) % capacity;
	list->length_a--;
	list->length_b++;
	// write(1, "pb\n", 3);
}
void	push_a(t_stack *list, int capacity)
{
	list->a_start = (list->a_start - 1 + capacity) % capacity;
	list->stack_a[list->a_start] = list->stack_b[list->b_start];
	list->b_start = (list->b_start + 1) % capacity;
	list->length_a++;
	list->length_b--;
	// write(1, "pa\n", 3);
}
void	rotate_both(t_stack *list, int capacity)
{
	rotate_a(list, capacity);
	rotate_b(list, capacity);
	// write(1, "rr\n", 3);
}