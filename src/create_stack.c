/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:39:53 by ikozhina          #+#    #+#             */
/*   Updated: 2025/02/24 22:21:58 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void calculate_numbers(int argc, char **argv, int *numbers_count)
{
	int i;
	int j;
	char **split_argv;

	if (argc < 2)
		return ;
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

t_stack *input_to_ar(int argc, char **argv)
{
	int i;
	int j;
	char **split_argv;
	int int_value;
	int numbers_count;
	t_stack	*stacks;

	numbers_count = 0;
	stacks = NULL;
	calculate_numbers(argc, argv, &numbers_count);
	intialise_struct(&stacks, numbers_count);
	if (!stacks || !stacks->stack_a || !stacks->stack_b)
	{
		free(stacks);
		return NULL;
	}
	i = 1;
	while (i < argc)
	{
		split_argv = ft_split(argv[i], ' ');
		j = 0;
		while(split_argv[j])
		{
			int_value = atoi_limits_check(split_argv[j]);
			duplicate_check(stacks->stack_a, stacks->a_end, int_value);
			stacks->stack_a[stacks->a_end++] = int_value;
			stacks->length_a++;
			j++;
		}
		free_split(split_argv);
		i++;
	}

	// printf("\nnot sorted\n");
	// print_circular_buffer_a(stacks, numbers_count);
	// printf("\nstart - %d end- %d\n", stacks->a_start, stacks->a_end);

	// // swap_a(&stacks);
	// rank_numbers(stacks, numbers_count);
	// printf("\nranked\n");
	// print_circular_buffer_a(stacks, numbers_count);

	// rotate_a(stacks, numbers_count);
	// printf("\nrotated\n");
	// print_circular_buffer_a(stacks, numbers_count);
	// // printf("\n");
	// // printf("start - %d end- %d\n", stacks->a_start, stacks->a_end);

	// // free(new_arr);
	stacks->a_end--;
	return(stacks);
}
void free_split(char **split_argv)
{
	int i;

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
