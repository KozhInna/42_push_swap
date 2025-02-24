/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:42:54 by ikozhina          #+#    #+#             */
/*   Updated: 2025/02/24 11:51:24 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<push_swap.h>

int main(int argc, char **argv)
{
	t_stack *stacks;

	stacks = input_to_ar(argc, argv);
	sorting(stacks, stacks->length_a);

	return(0);
} 






