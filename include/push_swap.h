/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:17:34 by ikozhina          #+#    #+#             */
/*   Updated: 2025/02/07 12:58:34 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

void	only_digits(char *s);
void	print_error(void);
void	is_empty_str(char *s);
int		atoi_limits_check(const char *nptr);
int		duplicate_check(int *new_arr, size_t arr_length, int int_value);

#endif
