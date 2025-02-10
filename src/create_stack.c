/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:39:53 by ikozhina          #+#    #+#             */
/*   Updated: 2025/02/10 15:08:17 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include<stdio.h>

void calculate_numbers(int argc, char **argv, size_t *numbers_count)
{
	int i;
	size_t j;
	char **split_argv;

	i = 1;
	while (i < argc)
	{
		is_empty_str(argv[i]);
		split_argv = ft_split(argv[i], ' ');
		j = 0;
		while(split_argv[j])
		{
			only_digits(split_argv[j]);
			atoi_limits_check(split_argv[j]);
			(*numbers_count)++;
			j++;
		}
		free_split(split_argv);
		i++;
	}
}

void input_to_ar(int argc, char **argv)
{
	int i;
	int j;
	char **split_argv;
	int int_value;
	size_t k;
	size_t numbers_count;
	t_list	*a_list;

	k = 0;
	numbers_count = 0;
	calculate_numbers(argc, argv, &numbers_count);
	intialise_struct(&a_list, numbers_count);
	if (!a_list || !a_list->stack_a)
		return ;
	i = 1;
	while (i < argc)
	{
		split_argv = ft_split(argv[i], ' ');
		j = 0;
		while(split_argv[j])
		{
			int_value = atoi_limits_check(split_argv[j]);
			duplicate_check(a_list->stack_a, k, int_value);
			a_list->stack_a[k++] = int_value;
			a_list->a_end++;
			j++;
		}
		free_split(split_argv);
		i++;
	}

	printf("numbers count %zu\n", numbers_count);

	k = 0;
	while (k < numbers_count)
	{
		printf("%d ", a_list->stack_a[k]);
		k++;
	}
	printf("\n");
	printf("start - %zu\n end- %zu\n", a_list->a_start, a_list->a_end);

	swap_a(&a_list);
		k = 0;
	while (k < numbers_count)
	{
		printf("%d ", a_list->stack_a[k]);
		k++;
	}
	printf("\n");
	printf("start - %zu\n end- %zu\n", a_list->a_start, a_list->a_end);
	// free(new_arr);
}
void free_split(char **split_argv)
{
	size_t i;

	i = 0;
	while (split_argv[i])
	{
		free(split_argv[i]);
		i++;
	}
	free(split_argv);
}

void	intialise_struct(t_list **list, size_t numbers_count)
{
	*list = malloc(sizeof(t_list));
	if (!(*list))
		return ;
	(*list)->length = numbers_count;
	(*list)->a_start = 0;
	(*list)->a_end = 0;
	(*list)->stack_a = malloc(sizeof(int) * numbers_count);

	if (!(*list)->stack_a)
	{
		free((*list));
		return ;
	}
}

