#include "includes/push_swap.h"
#include <stdio.h>

void	test(int *stack_a, int ac)
{
	int	i;

	i = 0;
	while (stack_a && i < ac)
	{
		printf("[%d]\n", stack_a[i]);
		i++;
	}
}

void	test_print_stack(t_temp *data)
{
	printf("\n");
	printf("stack_a:\n");
	test(data->stack_a, data->len_a);
	printf("stack_b:\n");
	test(data->stack_b, data->len_b);
}
