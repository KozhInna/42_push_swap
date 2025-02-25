#include "push_swap.h"

void print_circular_buffer_a(t_stack *stack, int capacity)
{
    if (stack->length_a == 0)
        return ;
	int k = stack->a_start;
    printf("start_a - %d end_a - %d\n", stack->a_start, stack->a_end);

	if (stack->a_start <= stack->a_end)
	{
		while (k <= stack->a_end)
			printf("%d ", stack->stack_a[k++]);
	}
	else
	{
		while (k < capacity)
			printf("%d ", stack->stack_a[k++]);
		k = 0;
		while (k <= stack->a_end)
			printf("%d ", stack->stack_a[k++]);
	}
    printf("\n");
}

void print_circular_buffer_b(t_stack *stack, int capacity)
{
    if (stack->length_b == 0)
        return ;
	int k = stack->b_start;
    // printf("start_b - %d end_b - %d\n", k, stack->b_end);

	if (stack->b_start <= stack->b_end)
	{
		while (k <= stack->b_end)
			printf("%d ", stack->stack_b[k++]);
	}
	else
	{
		while (k < capacity)
			printf("%d ", stack->stack_b[k++]);
		k = 0;
		while (k <= stack->b_end)
			printf("%d ", stack->stack_b[k++]);
	}
    printf("\n");
}