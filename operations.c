#include "includes/push_swap.h"
#include <stdio.h>

void op_s(int *stack, int len)
{
	ft_swap_int(&stack[0], &stack[1]);
}

void op_rr(int *stack, int len)
{
    int tmp_stack[len];
    int i;
    int j;
    int last;

    i = 1;
    j = 0;
    last = stack[len - 1];
	while(j < len - 1)
		tmp_stack[i++] = stack[j++];
	i = 0;
	j = 0;
	while (i < len)
		stack[i++] = tmp_stack[j++];
    stack[0] = last;
}

void op_r(int *stack, int len)
{
	int tmp_stack[len];
	int i;
	int j;
	int first;

	j = 1;
	i = 0;
	first = stack[0];
	while(i < len - 1)
		tmp_stack[i++] = stack[j++];
	i = 0;
	j = 0;
	while(i < len - 1)
		stack[i++] = tmp_stack[j++];
	stack[len - 1] = first;
}

int *op_pb(int *stack_a, int len, t_temp *data)
{
	int *stack_b;
	int i;
	int j;

	data->len_a--;
	data->len_b++;
	i = 0;
	j = 1;
	free(stack_a);
	stack_a = malloc(sizeof(int) * data->len_a);
	while(j < data->len_a)
		stack_a[i++] = data->stack_a[j++];
	data->stack_b = stack_b;
	return (stack_b);
}