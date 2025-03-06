/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:56:20 by ikozhina          #+#    #+#             */
/*   Updated: 2025/03/06 15:09:00 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	duplicate_check(char **split_argv, t_stack *list, int int_value)
{
	int	i;

	i = 0;
	if (!list || !list->stack_a)
		return ;
	while (i < list->a_end)
	{
		if (list->stack_a[i] == int_value)
		{
			free_struct(list);
			print_error_free(split_argv);
		}
		i++;
	}
}

void	only_digits(char **split_argv, char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i] || !ft_isdigit(s[i]))
		print_error_free(split_argv);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			print_error_free(split_argv);
		i++;
	}
}

void	is_empty_str(char *s)
{
	if (!s)
		print_error();
	while (*s)
	{
		if (*s != ' ')
			return ;
		s++;
	}
	print_error();
}

int	atoi_limits_check(char **split_argv, const char *nptr)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*nptr == ' ' || *nptr == '\f' || *nptr == '\n' || *nptr == '\r'
		|| *nptr == '\t' || *nptr == '\v')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - '0');
		if (sign == 1 && res > INT_MAX)
			print_error_free(split_argv);
		if (sign == -1 && - res < INT_MIN)
			print_error_free(split_argv);
		nptr++;
	}
	return ((int)(res * sign));
}

int	is_sorted(t_stack *list, int capacity)
{
	int	i;
	int	index;
	int	next_index;

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
