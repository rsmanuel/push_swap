#include "includes/push_swap.h"
#include <stdio.h>


int *create_stackb(int len)
{
	int *stack_b;

	stack_b = malloc(sizeof(int) * len - 1);
	if (!stack_b)
		return NULL;
	return (stack_b);
}
