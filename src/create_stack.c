/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:39:53 by ikozhina          #+#    #+#             */
/*   Updated: 2025/03/06 14:40:49 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*input_to_ar(int argc, char **argv)
{
	int		numbers_count;
	t_stack	*list;

	numbers_count = 0;
	list = NULL;
	calculate_numbers(argc, argv, &numbers_count);
	intialise_struct(&list, numbers_count);
	if (!list)
		return (NULL);
	fill_stack_a(argc, argv, list);
	rank_numbers(list, numbers_count);
	return (list);
}

void	calculate_numbers(int argc, char **argv, int *numbers_count)
{
	int		i;
	int		j;
	char	**split_argv;

	if (argc < 2)
		return ;
	i = 1;
	while (i < argc)
	{
		is_empty_str(argv[i]);
		split_argv = ft_split(argv[i], ' ');
		if (!split_argv)
			exit(1);
		j = 0;
		while (split_argv[j])
		{
			only_digits(split_argv, split_argv[j]);
			atoi_limits_check(split_argv, split_argv[j]);
			(*numbers_count)++;
			j++;
		}
		free_split(split_argv);
		i++;
	}
}

void	fill_stack_a(int argc, char **argv, t_stack *list)
{
	int		i;
	int		j;
	int		int_value;
	char	**split_argv;

	i = 1;
	while (i < argc)
	{
		split_argv = ft_split(argv[i], ' ');
		if (!split_argv)
			exit(1);
		j = 0;
		while (split_argv[j])
		{
			int_value = atoi_limits_check(split_argv, split_argv[j]);
			duplicate_check(split_argv, list, int_value);
			list->stack_a[list->a_end] = int_value;
			list->length_a++;
			if (list->length_a != list->capacity)
				list->a_end++;
			j++;
		}
		free_split(split_argv);
		i++;
	}
}

void	intialise_struct(t_stack **list, int numbers_count)
{
	*list = malloc(sizeof(t_stack));
	if (!(*list))
		return ;
	(*list)->capacity = numbers_count;
	(*list)->length_a = 0;
	(*list)->a_start = 0;
	(*list)->a_end = 0;
	(*list)->length_b = 0;
	(*list)->b_start = 0;
	(*list)->b_end = 0;
	(*list)->stack_a = malloc(sizeof(int) * numbers_count);
	if (!(*list)->stack_a)
	{
		free((*list));
		*list = NULL;
		return ;
	}
	(*list)->stack_b = malloc(sizeof(int) * numbers_count);
	if (!(*list)->stack_b)
	{
		free((*list)->stack_a);
		free((*list));
		*list = NULL;
		return ;
	}
}
