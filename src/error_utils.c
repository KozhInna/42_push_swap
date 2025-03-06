/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:33:48 by ikozhina          #+#    #+#             */
/*   Updated: 2025/03/06 15:09:14 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	free_struct(t_stack *list)
{
	if (!list)
		return ;
	free(list->stack_a);
	free(list->stack_b);
	free(list);
}

void	print_error_free(char **split_argv)
{
	ft_putstr_fd("Error\n", 2);
	if (split_argv)
		free_split(split_argv);
	exit(1);
}

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
