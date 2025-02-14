/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:53:36 by ikozhina          #+#    #+#             */
/*   Updated: 2025/02/14 15:06:07 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	is_pivot(t_stack *stack, int length)
{
	int min;
	int max;
	int median;
	int i;
	int count;

	min = stack->stack_a[stack->a_start];
	max = stack->stack_a[stack->a_end];
	i = stack->a_start;
	count = 0;

	while (count < length)
	{
		if (stack->stack_a[i] < min)
			min = stack->stack_a[i];
		else if (stack->stack_a[i] > max)
			max = stack->stack_a[i];
		i = (i + 1) % length;
		count++;

	}
	median = min + ((max - min) / 2);


	printf("\npi_start - %d pi_end- %d\n", stack->a_start, stack->a_end);
	return (median);
}
