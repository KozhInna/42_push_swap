/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:42:54 by ikozhina          #+#    #+#             */
/*   Updated: 2025/03/05 14:13:40 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int argc, char **argv)
{
	t_stack	*stacks;

	stacks = input_to_ar(argc, argv);
	sorting(stacks, stacks->capacity);
	free_struct(stacks);
	return (0);
}

void	free_struct(t_stack *list)
{
	if (!list)
		return ;
	free(list->stack_a);
	free(list->stack_b);
	free(list);
}
