/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:19:53 by ikozhina          #+#    #+#             */
/*   Updated: 2025/02/28 10:47:39 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void    sort_three(t_stack *list, int capacity)
{
    int min;

    min = find_min(list);
    if (min == list->stack_a[list->a_start + 1])
    {
        if (list->max == list->stack_a[list->a_start])
            rotate_a(list, capacity);
        else
            swap_a(list, capacity);
    }
    else if (min == list->stack_a[list->a_end])
    {
        if (list->max == list->stack_a[list->a_start + 1])
            rrotate_a(list, capacity);
        else
        {
            swap_a(list, capacity);
            rrotate_a(list, capacity);
        }
    }
    else
    {
        swap_a(list, capacity);
        rotate_a(list, capacity);
    }
}
