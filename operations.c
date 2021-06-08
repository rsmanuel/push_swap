#include "includes/push_swap.h"
#include <stdio.h>

int	*op_s(int *stack, int len)
{
	int *new_stack;

	new_stack = stack;
	ft_swap_int(&stack[len - 1], &stack[len - 2]);

	return (new_stack);
}

int *op_rr(int *stack, int len)
{
    int *new_stack;
    int last;
    int i;
    int j;

    last = stack[len - 1];
    new_stack[0] = last;
    i = 1;
    j = 0;
    while (i < len && j < len)
        new_stack[i++] = stack[j++];

    return (new_stack);
}

int *op_r(int *stack, int len)
{
    int *new_stack;
    int first;
    int i;
    int j;

    first = stack[0];
    new_stack[len - 1] = first;
    i = 0;
    j = 1;
    while (i < len - 1 && j < len)
        new_stack[i++] = stack[j++];

    return (new_stack);
}

void op_p(int *stack_from, int *stack_to, int len)
{
    free(stack_to);
    stack_to = malloc(sizeof(int) * len + 1);
    stack_to[len + 1] = 0;
    if(!stack_to)
        return ;   
    ft_swap_int(&stack_from[len], &stack_to[len + 1]);
}