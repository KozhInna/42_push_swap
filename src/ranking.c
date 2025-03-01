/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:07:13 by ikozhina          #+#    #+#             */
/*   Updated: 2025/02/28 15:44:53 by ikozhina         ###   ########.fr       */
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
	find_max_a(list, list->capacity);
}
int find_max_a(t_stack *list, int capacity)
{
	int	max;
	int	i;
	int start;

	i = 0;
	start = list->a_start;
	max = list->stack_a[start];
	while (i < list->length_a - 1)
	{
		start = (start + 1) % capacity;
		if (max < list->stack_a[start])
			max = list->stack_a[start];
		i++;
	}
	list->max = max;
	return (max);
}
int	find_min_a(t_stack *list, int capacity)
{
	int	min;
	int	i;
	int start;

	i = 0;
	start = list->a_start;
	min = list->stack_a[start];
	while (i < list->length_a - 1)
	{
		start = (start + 1) % capacity;
		if (min > list->stack_a[start])
			min = list->stack_a[start];
		i++;
	}
	return (min);
}