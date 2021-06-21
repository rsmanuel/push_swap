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

void op_pb_aux(t_temp *data, int i, int j, int *stack_b)
{
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
		i = 0;
		j = 0;
		while(i < data->len_b)
			stack_b[i++] = data->stack_b[j++]; 
		i = 1;
		j = 0;
		data->len_b++;
		while(i < data->len_b)
			data->stack_b[i++] = stack_b[j++];
		data->stack_b[0] = data->stack_a[0];
	}
}

void	op_pb(t_temp *data)
{
	int *new_stack;
	int *stack_b;
	int i;
	int j;

	i = 0;
	j = 1;
	stack_b = malloc(sizeof(int) * data->len_b);
	new_stack = malloc(sizeof(int) * data->len_a);
	op_pb_aux(data, i, j, stack_b);
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
	free(stack_b);
	free(new_stack);
}

void op_pa_aux(t_temp *data, int i, int j, int *stack_a)
{
	if (!data->len_a)
	{
		data->stack_a[0] = data->stack_b[0];
		data->len_a++;
	}
	else if(!data->len_b)
	{
		return ;
	}
	else
	{
		i = 0;
		j = 0;
		while(i < data->len_a)
			stack_a[i++] = data->stack_a[j++]; 
		i = 1;
		j = 0;
		data->len_a++;
		while(i < data->len_a)
			data->stack_a[i++] = stack_a[j++];
		data->stack_a[0] = data->stack_b[0];
	}
}

void	op_pa(t_temp *data)
{
	int *new_stack;
	int *stack_a;
	int i;
	int j;

	i = 0;
	j = 1;
//op_pb_aux(data, i, j, stack_a);
	new_stack = data->stack_b;
	while(i < data->len_b - 1)
		new_stack[i++] = data->stack_b[j++];
	i = 0;
	j = 0;
	while (i < data->len_b - 1)
		data->stack_b[i++] = new_stack[j++];
	data->top_a = data->stack_b[0];
	data->top_b = data->stack_a[0];
	data->len_b--;
}
