#include "includes/push_swap.h"
#include <stdio.h>

int *create_stackb(int len)
{
	int *stack_b;

	stack_b = ft_calloc(len	, sizeof(int));
	if (!stack_b)
		return NULL;
	return (stack_b);
}
