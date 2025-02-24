/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:18:09 by ikozhina          #+#    #+#             */
/*   Updated: 2025/02/24 22:14:13 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swap_a(t_stack *list, int length)
{
	int start;
	int end;
	int	temp;

	start = list->a_start;
	end = list->a_end;
	if (start == end)
		return;
	temp = list->stack_a[start];
	list->stack_a[start] = list->stack_a[(start + 1) % length];
	list->stack_a[(start + 1) % length] = temp;
	// write(1, "sa\n", 3);
}

void	rotate_a(t_stack *list, int capacity)
{
	// int start;
	// int end;

	// start = list->a_start;
	printf("start A - %d", list->a_start);
	// end = list->a_end;
	if (list->a_start == list->a_end)
		return ;
	list->a_end = (list->a_end + 1) % capacity;
	list->stack_a[list->a_end] = list->stack_a[list->a_start];
	list->a_start = (list->a_start + 1) % capacity;
	// write(1, "ra\n", 3);
}
