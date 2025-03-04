/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:56:20 by ikozhina          #+#    #+#             */
/*   Updated: 2025/03/04 13:30:17 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void duplicate_check(int *new_arr, int arr_length, int int_value)
{
    int i;

    i = 0;
    if (!new_arr)
        return ;
    while (i < arr_length)
    {
        if (new_arr[i] == int_value)
			ft_putstr_fd("Error\n", 2);
        i++;
	}
}

void only_digits(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!ft_isdigit(s[i]))
		ft_putstr_fd("Error\n", 2);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			ft_putstr_fd("Error\n", 2);
		i++;
	}
}
void is_empty_str(char *s)
{
	if (!s)
		ft_putstr_fd("Error\n", 2);
	while(*s)
	{
		if (*s != ' ')
			return ;
		s++;
	}
	ft_putstr_fd("Error\n", 2);
}

int	atoi_limits_check(const char *nptr)
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
			ft_putstr_fd("Error\n", 2);
        if (sign == -1 && -res < INT_MIN)
			ft_putstr_fd("Error\n", 2);
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
