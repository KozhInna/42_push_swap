/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_or_less.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:19:53 by ikozhina          #+#    #+#             */
/*   Updated: 2025/03/02 22:56:52 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void    sort_five_or_less(t_stack *list, int capacity)
{
   
        if (list->length_a == 3)
            sort_three(list, capacity);
        else
            sort_five(list, capacity);
}

void    sort_five(t_stack *list, int capacity)
{
    int min;
    int i;
    int len_b;
    
    i = 0;
    while (list->length_a > 3)
    {
        min = find_min_a(list, capacity);
        if (list->stack_a[(list->a_start + i) % capacity] == min)
        {
            while (list->stack_a[list->a_start] != min)
                rotate_a(list, capacity);
            push_b(list, capacity);
            i = 0;
        }
        else if (list->stack_a[(list->a_end - i + capacity) % capacity] == min)
        {
            while (list->stack_a[list->a_start] != min)
                rrotate_a(list, capacity);
            push_b(list, capacity);
            i = 0;
        }
        else
            i++;
    }
        // printf("\n---1---\n");
        // printf("A - ");
        // print_circular_buffer_a(list, list->capacity);
        // printf("B - ");
        // print_circular_buffer_b(list, list->capacity);
    sort_three(list, capacity);
        // printf("---2---\n");
        // printf("A - ");
        // print_circular_buffer_a(list, list->capacity);
        // printf("B - ");
        // print_circular_buffer_b(list, list->capacity);
    len_b = list->length_b;
    while (len_b > 0)
    {
        push_a(list, capacity);
        len_b--;
    }
}

void    sort_three(t_stack *list, int capacity)
{
    int min;
    int max;

    if (is_sorted(list, capacity))
        return ;
    min = find_min_a(list, capacity);
    max = find_max_a(list, capacity);
    if (min == list->stack_a[(list->a_start + 1) % capacity])
    {
        if (max == list->stack_a[list->a_start])
            rotate_a(list, capacity);
        else
            swap_a(list, capacity);
    }
    else if (min == list->stack_a[list->a_end])
    {
       
        if (max == list->stack_a[(list->a_start + 1) % capacity])
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

int is_sorted(t_stack *list, int capacity)
{
    int i;
    int index;
    int next_index;

    i = 0;
    index = list->a_start;
    while (i < list->length_a - 1)
    {
        next_index = (index + 1) % capacity;
        if (list->stack_a[index] > list->stack_a[next_index])
            return (0);
        index = next_index;
        i++;
    }
    return (1);
}
