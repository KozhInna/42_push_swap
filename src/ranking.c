/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:07:13 by ikozhina          #+#    #+#             */
/*   Updated: 2025/02/25 22:15:14 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	rank_numbers(t_stack *list, int length)
{
	int	value;
	int	count;
	int i;
	int j;
	int *ranked_arr;

	i = 0;
	ranked_arr = malloc(sizeof(int) * length);
	if(!ranked_arr)
		return ;
	while (i < length)
	{
		value = list->stack_a[i];
		count = 1;
		j = 0;
		while (j < length)
			if (value > list->stack_a[j++])
				count++;
		ranked_arr[i++] = count;
	}
	free(list->stack_a);
	list->stack_a = ranked_arr;
	find_max(list);
}
void find_max(t_stack *list)
{
	int	max;
	int	i;

	i = 0;
	max = list->stack_a[i];
	while (i < list->length_a)
	{
		if (max < list->stack_a[i])
			max = list->stack_a[i];
		i++;
	}
	list->max = max;
}