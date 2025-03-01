/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_or_less.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:19:53 by ikozhina          #+#    #+#             */
/*   Updated: 2025/03/01 09:17:29 by ikozhina         ###   ########.fr       */
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
    int start;
    int end;
    int min;
    int count = list->length_a - 3;
    int i = 0;
    
    while (count > 0)
    {
        if (i == (list->length_a / 2))
        {
            rotate_a(list, capacity);
            i = 0;
        }
        min = find_min_a(list, capacity);
        start = list->a_start;
        end = list->a_end;
        if (list->stack_a[start + i] == min)
        {
            if (i == 1)
                swap_a(list, capacity);
            push_b(list, capacity);
            count--;
            i = 0;
        }
        else if (list->stack_a[end - i] == min)
        {
            if (i == 1)
                rrotate_a(list, capacity);
            rrotate_a(list, capacity);
            push_b(list, capacity);
            count--;
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

    i = 0;
    int len_b = list->length_b;
    while (i < len_b)
    {
        push_a(list, capacity);
        i++;
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
        {
            // printf("here1");
            rotate_a(list, capacity);
        }
        else
        {
            // printf("here2");
            swap_a(list, capacity);
        }
    }
    else if (min == list->stack_a[list->a_end])
    {
       
        if (max == list->stack_a[(list->a_start + 1) % capacity])
        {
            // printf("here");
            rrotate_a(list, capacity);
        }
        else
        {
            // printf("here3\n");
            swap_a(list, capacity);
            rrotate_a(list, capacity);
        }
    }
    else
    {
        // printf("here5\n");
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
