/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:18:09 by ikozhina          #+#    #+#             */
/*   Updated: 2025/02/10 15:09:58 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swap_a(t_list **list)
{
	size_t start;
	int	temp;

	start = (*list)->a_start;
	temp = (*list)->stack_a[start];
	(*list)->stack_a[start] = (*list)->stack_a[start + 1];
	(*list)->stack_a[start + 1] = temp;
	write(1, "sa\n", 3);
}


