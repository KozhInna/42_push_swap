/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:17:34 by ikozhina          #+#    #+#             */
/*   Updated: 2025/02/28 10:48:02 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
#include<stdio.h>

typedef struct s_stack
{
	int capacity;
	int	max;
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
void	print_error(void);
void	is_empty_str(char *s);
void	free_split(char **split_argv);
void	duplicate_check(int *new_arr, int arr_length, int int_value);
void	intialise_struct(t_stack **list, int numbers_count);
t_stack *input_to_ar(int argc, char **argv);

void	swap_a(t_stack *list, int length);
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
void	initial_split(t_stack *list, int length);
void    final_merge(t_stack *list, int capacity);
void	find_max(t_stack *list);
int		find_min(t_stack *list);
int		count_bits(int max);
void    sort_three(t_stack *list, int capacity);

void 	print_circular_buffer_a(t_stack *stack, int length);
void 	print_circular_buffer_b(t_stack *stack, int length);

#endif
