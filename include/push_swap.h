/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:17:34 by ikozhina          #+#    #+#             */
/*   Updated: 2025/02/14 14:46:06 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
#include<stdio.h>

typedef struct s_stack
{
	int	length;
	int	a_start;
	int	a_end;
	int		*stack_a;
	int	b_start;
	int	b_end;
	int		*stack_b;
}	t_stack;



// typedef struct s_list
// {
// 	int	b_start;
// 	int	b_end;
// 	int	*stack_b;
// }	b_list;

void	only_digits(char *s);
void	print_error(void);
void	is_empty_str(char *s);
void	free_split(char **split_argv);
void	duplicate_check(int *new_arr, int arr_length, int int_value);
void	intialise_struct(t_stack **list, int numbers_count);
void	swap_a(t_stack *list, int length);
void	rotate_a(t_stack *list, int length);
void	rank_numbers(t_stack *list, int length);
void 	print_circular_buffer_a(t_stack *stack, int length);
int		atoi_limits_check(const char *nptr);
int		is_pivot(t_stack *stack, int length);

#endif
