/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:39:53 by ikozhina          #+#    #+#             */
/*   Updated: 2025/03/05 14:13:36 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*input_to_ar(int argc, char **argv)
{
	int		numbers_count;
	t_stack	*stacks;

	numbers_count = 0;
	stacks = NULL;
	calculate_numbers(argc, argv, &numbers_count);
	intialise_struct(&stacks, numbers_count);
	if (!stacks || !stacks->stack_a || !stacks->stack_b)
	{
		free_struct(stacks);
		return (NULL);
	}
	fill_stack_a(argc, argv, stacks);
	rank_numbers(stacks, numbers_count);
	return (stacks);
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
		j = 0;
		while (split_argv[j])
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

void	fill_stack_a(int argc, char **argv, t_stack *stacks)
{
	int		i;
	int		j;
	int		int_value;
	char	**split_argv;

	i = 1;
	while (i < argc)
	{
		split_argv = ft_split(argv[i], ' ');
		j = 0;
		while (split_argv[j])
		{
			int_value = atoi_limits_check(split_argv[j]);
			duplicate_check(stacks->stack_a, stacks->a_end, int_value);
			stacks->stack_a[stacks->a_end] = int_value;
			stacks->length_a++;
			if (stacks->length_a != stacks->capacity)
				stacks->a_end++;
			j++;
		}
		free_split(split_argv);
		i++;
	}
}

void	free_split(char **split_argv)
{
	int	i;

	i = 0;
	while (split_argv[i])
	{
		free(split_argv[i]);
		i++;
	}
	free(split_argv);
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
