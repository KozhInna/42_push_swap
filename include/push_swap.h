/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:17:34 by ikozhina          #+#    #+#             */
/*   Updated: 2025/03/04 13:32:32 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
#include<stdio.h>

typedef struct s_stack
{
	int capacity;
	int	length_a;
	int	a_start;
	int	a_end;
	int		*stack_a;
	int	length_b;
	int	b_start;
	int	b_end;
	int		*stack_b;
}	t_stack;

void	only_digits(char *s);
void	is_empty_str(char *s);
void	free_split(char **split_argv);
void	duplicate_check(int *new_arr, int arr_length, int int_value);
void	intialise_struct(t_stack **list, int numbers_count);
t_stack *input_to_ar(int argc, char **argv);
void	fill_stack_a(int argc, char **argv, t_stack *stacks);
void 	calculate_numbers(int argc, char **argv, int *numbers_count);

void	swap_a(t_stack *list, int length);
void	swap_b(t_stack *list, int capacity);
void	rotate_a(t_stack *list, int length);
void	rrotate_a(t_stack *list, int capacity);
void	rotate_b(t_stack *list, int capacity);
void	push_b(t_stack *list, int capacity);
void	push_a(t_stack *list, int capacity);
void	rotate_both(t_stack *list, int capacity);

void    radix_sort(t_stack *list, int capacity);
void	rank_numbers(t_stack *list, int length);
int		atoi_limits_check(const char *nptr);
void	sorting(t_stack *list, int length);
int		find_max_a(t_stack *list, int capacity);
int		find_min_a(t_stack *list, int capacity);
int		count_bits(int max);
void    sort_three(t_stack *list, int capacity);
void    sort_five_or_less(t_stack *list, int capacity);
void    sort_five(t_stack *list, int capacity);
int 	is_sorted(t_stack *list, int capacity);
void    sort_hundred(t_stack *list, int capacity);
int 	find_max_b(t_stack *list, int capacity);
void	rrotate_b(t_stack *list, int capacity);
void 	process_stack_a(t_stack *list, int capacity, int len_a, int i);
void 	process_stack_b(t_stack *list, int capacity, int len_b, int i);
void	free_struct(t_stack *list);

void 	print_circular_buffer_a(t_stack *stack, int length);
void 	print_circular_buffer_b(t_stack *stack, int length);

#endif
