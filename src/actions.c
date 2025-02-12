/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:18:09 by ikozhina          #+#    #+#             */
/*   Updated: 2025/02/12 21:45:00 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include<stdio.h>

void	swap_a(t_stack **list, int length)
{
	int start;
	int end;
	int	temp;

	start = (*list)->a_start;
	end = (*list)->a_end;
	if (start == end)
		return;
	temp = (*list)->stack_a[start];
	(*list)->stack_a[start] = (*list)->stack_a[(start + 1) % length];
	(*list)->stack_a[(start + 1) % length] = temp;
	write(1, "sa\n", 3);
}

void	rotate_a(t_stack **list, int length)
{
	int start;
	int end;

	start = (*list)->a_start;
	end = (*list)->a_end;
	if (start == end)
		return ;
	(*list)->a_end = (end + 1) % length;
	(*list)->a_start = (start + 1) % length;
	// write(1, "ra\n", 3);

	// if (end < length - 1)
	// 	end++;
	// else
	// 	end = 0;
}
