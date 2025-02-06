/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:42:54 by ikozhina          #+#    #+#             */
/*   Updated: 2025/02/06 22:50:21 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<push_swap.h>
#include<stdio.h>

void input_to_ar(int argc, char **argv);
void only_digits(char *s);
void make_arr(int value, int **arr, size_t *capacity, size_t *length);
void print_error(void);
int	atoi_limits_check(const char *nptr);
void is_empty_str(char *s);
int is_duplicate(int *new_arr, size_t arr_length, int int_value);

int main(int argc, char **argv)
{
	if (argc < 2)
		return (0);

	input_to_ar(argc, argv);

	return(0);
}

void input_to_ar(int argc, char **argv)
{
	int i;
	int j;
	char **split_argv;
	int int_value;
	int *new_arr;
	size_t arr_length;
	size_t capacity;

	capacity = 5;
	new_arr = malloc(sizeof(int) * capacity);
	if (!new_arr)
		return ;
	arr_length = 0;
	i = 1;
	while (i < argc)
	{
		is_empty_str(argv[i]);
		split_argv = ft_split(argv[i], ' ');
		j = 0;
		while(split_argv[j])
		{
			only_digits(split_argv[j]);
			int_value = atoi_limits_check(split_argv[j]);
            if (!is_duplicate(new_arr, arr_length, int_value))
			    make_arr(int_value, &new_arr, &capacity, &arr_length);
			j++;
		}
		i++;
	}
	printf("ar length - %zu\n", arr_length);
	printf("ar capacity - %zu\n", capacity);

	size_t k = 0;
	while (k < arr_length)
	{
		printf("%d ", new_arr[k]);
		k++;
	}
}

int is_duplicate(int *new_arr, size_t arr_length, int int_value)
{
    size_t i;

    i = 0;
    if (!new_arr)
        return (0);
    while (i < arr_length)
    {
        if (new_arr[i] == int_value)
            print_error();
        i++;
    }
    return (0);
}

void make_arr(int value, int **arr, size_t *capacity, size_t *length)
{
	int *temp_arr;
	size_t i;

	temp_arr = NULL;
	i = 0;
	if (*length >= *capacity)
	{
		temp_arr = malloc(sizeof(int) * 2 * (*capacity));
		*capacity *= 2;
		while(i < *length)
		{
			temp_arr[i] = (*arr)[i];
			i++;
		}
		free(*arr);
		*arr = temp_arr;
	}
	(*arr)[*length] = value;
	(*length)++;
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

void print_error(void)
{
	write(2, "Error\n", 6);
	exit (1);
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

