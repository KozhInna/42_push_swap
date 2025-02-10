/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:17:34 by ikozhina          #+#    #+#             */
/*   Updated: 2025/02/10 15:05:25 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_list
{
	size_t	length;
	size_t	a_start;
	size_t	a_end;
	int		*stack_a;
	size_t	b_start;
	size_t	b_end;
	int		*stack_b;
}	t_list;

// typedef struct s_list
// {
// 	size_t	b_start;
// 	size_t	b_end;
// 	int	*stack_b;
// }	b_list;

void	only_digits(char *s);
void	print_error(void);
void	is_empty_str(char *s);
void	free_split(char **split_argv);
void	duplicate_check(int *new_arr, size_t arr_length, int int_value);
void	intialise_struct(t_list **list, size_t numbers_count);
void	swap_a(t_list **list);
int		atoi_limits_check(const char *nptr);

#endif
