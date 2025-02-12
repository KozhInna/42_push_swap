/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:56:20 by ikozhina          #+#    #+#             */
/*   Updated: 2025/02/12 10:23:47 by ikozhina         ###   ########.fr       */
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
            print_error();
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
		print_error();
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			print_error();
		i++;
	}
}
void is_empty_str(char *s)
{
	if (!s)
		print_error();
	while(*s)
	{
		if (*s != ' ')
			return ;
		s++;
	}
	print_error();
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
			print_error();
        if (sign == -1 && -res < INT_MIN)
		    print_error();
		nptr++;
	}
	return ((int)(res * sign));
}

void print_error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}
