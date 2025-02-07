/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:42:54 by ikozhina          #+#    #+#             */
/*   Updated: 2025/02/07 13:39:49 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<push_swap.h>

// void make_arr(int value, int **arr, size_t *capacity, size_t *length);
void input_to_ar(int argc, char **argv);

int main(int argc, char **argv)
{
	if (argc < 2)
		return (0);

	//check input and count numbers

	input_to_ar(argc, argv);

	return(0);
}







