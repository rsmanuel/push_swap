#include "includes/push_swap.h"
#include <stdio.h>

void op_s(int *stack)
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

void	op_pb(t_temp *data)
{
	int *new_stack;
	int *stack_b;
	int i;
	int j;
	if (!data->len_b)
	{
		data->stack_b[0] = data->stack_a[0];
		data->len_b++;
	}
	else if(!data->len_a)
	{
		return ;
	}
	else
	{
		i = 1;
		j = 0;
		stack_b = data->stack_b;
		data->len_b++;
		while(i < data->len_b)
		{
			data->stack_b[i] = stack_b[j];
			i++;
			j++;
		}
		data->stack_b[0] = data->stack_a[0];
	}
	i = 0;
	j = 1;
	new_stack = data->stack_a;
	while(i < data->len_a - 1)
		new_stack[i++] = data->stack_a[j++];
	i = 0;
	j = 0;
	while (i < data->len_a - 1)
		data->stack_a[i++] = new_stack[j++];
	data->top_a = data->stack_a[0];
	data->top_b = data->stack_b[0];
	data->len_a--;
}