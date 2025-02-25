/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:44:28 by ikozhina          #+#    #+#             */
/*   Updated: 2025/02/25 09:03:24 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void sorting(t_stack *list, int length)
{
    initial_split(list, length);
}
void initial_split(t_stack *list, int length_a)
{
    printf("_A_\n");
    printf("lenght_a - %d lenght_b - %d\n", list->length_a, list->length_b);
    print_circular_buffer_a(list, length_a);
    int currect_index;

    currect_index = 0;
    while (currect_index < length_a)
    {   
        if(list->stack_a[list->a_start] & 1)
        {
            push_b(list, list->capacity);
        }
        else
        {
            rotate_a(list, list->capacity);
        }
        currect_index++;
    }
    list->b_end = list->b_start + list->length_b - 1;
    printf("\n_B_\n");
    printf("lenght_a - %d lenght_b - %d\n", list->length_a, list->length_b);
    print_circular_buffer_b(list, list->length_b);
    printf("_A_\n");
    print_circular_buffer_a(list, list->length_a);
}
