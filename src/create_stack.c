/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:39:53 by ikozhina          #+#    #+#             */
/*   Updated: 2025/02/12 21:48:44 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include<stdio.h>

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

void input_to_ar(int argc, char **argv)
{
	int i;
	int j;
	char **split_argv;
	int int_value;
	int k;
	int numbers_count;
	t_stack	*a_list;

	k = 0;
	numbers_count = 0;
	a_list = NULL;
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

	// printf("numbers count %d\n", numbers_count);

	// k = 0;
	// while (k < numbers_count)
	// {
	// 	printf("%d ", a_list->stack_a[k]);
	// 	k++;
	// }
	printf("\nnot sorted\n");
	print_circular_buffer_a(a_list, numbers_count);
	printf("\nstart - %d end- %d\n", a_list->a_start, a_list->a_end);

	// swap_a(&a_list);
	rank_numbers(&a_list, numbers_count);
	printf("\nranked\n");
	print_circular_buffer_a(a_list, numbers_count);
	rotate_a(&a_list, numbers_count);
	printf("\nrotated\n");
	print_circular_buffer_a(a_list, numbers_count);
	printf("\n");
	printf("start - %d end- %d\n", a_list->a_start, a_list->a_end);

	printf("\n1 - %d\n", a_list->stack_a[a_list->a_start]);
	printf("\n2 - %d\n", a_list->stack_a[a_list->a_start + 1]);
	printf("\n3 - %d\n", a_list->stack_a[a_list->a_end]);
	// free(new_arr);
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
	(*list)->length = numbers_count;
	(*list)->a_start = 0;
	(*list)->a_end = -1;
	(*list)->stack_a = malloc(sizeof(int) * numbers_count);

	if (!(*list)->stack_a)
	{
		free((*list));
		return ;
	}
}

 void print_circular_buffer_a(t_stack *stack, int length)
{
	int k = stack->a_start;
	
	if (stack->a_start <= stack->a_end)
	{	
		while (k <= stack->a_end)
			printf("%d ", stack->stack_a[k++]);
	}
	else
	{
		while (k < length)
			printf("%d ", stack->stack_a[k++]);
		k = 0;
		while (k <= stack->a_end)
			printf("%d ", stack->stack_a[k++]);
	}

}
