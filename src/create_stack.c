/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:39:53 by ikozhina          #+#    #+#             */
/*   Updated: 2025/02/07 13:58:40 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

size_t calculate_numbers(int argc, char **argv, size_t *numbers_count)
{
	size_t i;
	size_t j;
	char **split_argv;
	int int_value;

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
			// duplicate_check(new_arr, arr_length, int_value);
            // if (!duplicate_check(new_arr, arr_length, int_value))
			    // make_arr(int_value, &new_arr, &capacity, &arr_length);
			numbers_count++;
			j++;
		}
		i++;
	}
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
	size_t numbers_count;

	numbers_count = 0;
	capacity = 5;
	new_arr = malloc(sizeof(int) * capacity);
	if (!new_arr)
		return ;
	arr_length = 0;
	i = 1;
	//calculate number of numbers and check input (if error --> send error and stop)
	// while (i < argc)
	// {
	// 	is_empty_str(argv[i]);
	// 	split_argv = ft_split(argv[i], ' ');
	// 	j = 0;
	// 	while(split_argv[j])
	// 	{
	// 		only_digits(split_argv[j]);
	// 		int_value = atoi_limits_check(split_argv[j]);
	// 		duplicate_check(new_arr, arr_length, int_value);
    //         // if (!duplicate_check(new_arr, arr_length, int_value))
	// 		    // make_arr(int_value, &new_arr, &capacity, &arr_length);
	// 		numbers_count++;
	// 		j++;
	// 	}
	// 	i++;
	// }
	calculate_numbers(argc, argv, &numbers_count);
	printf("number of numbers %zu\n", numbers_count);
	printf("ar length - %zu\n", arr_length);
	printf("ar capacity - %zu\n", capacity);

	size_t k = 0;
	while (k < arr_length)
	{
		printf("%d ", new_arr[k]);
		k++;
	}
}
