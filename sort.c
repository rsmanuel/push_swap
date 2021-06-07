#include "includes/push_swap.h"
#include <stdio.h>


int *create_stackb(int len)
{
	int *stack_b;

	stack_b = malloc(sizeof(int) * len);
	if (!stack_b)
		return (1);
	return (stack_b);
}
