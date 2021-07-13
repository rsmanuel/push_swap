#include "includes/push_swap.h"
#include <stdio.h>

void	op_pb_aux(t_temp *data, int i, int j, int *stack_b)
{
	if (!data->len_b)
	{
		data->stack_b[0] = data->stack_a[0];
		data->len_b++;
	}
	else if (!data->len_a)
	{
		return ;
	}
	else
	{
		i = 0;
		j = 0;
		while (i < data->len_b)
			stack_b[i++] = data->stack_b[j++];
		i = 1;
		j = 0;
		data->len_b++;
		while (i < data->len_b)
			data->stack_b[i++] = stack_b[j++];
		data->stack_b[0] = data->stack_a[0];
	}
}

void	pb(t_temp *data)
{
	int	*new_stack;
	int	*stack_b;
	int	i;
	int	j;

	i = 0;
	j = 1;
	new_stack = malloc(sizeof(int) * data->len_a);
	stack_b = malloc(sizeof(int) * data->len_b);
	op_pb_aux(data, i, j, stack_b);
	while (i < data->len_a - 1)
		new_stack[i++] = data->stack_a[j++];
	i = 0;
	j = 0;
	while (i < data->len_a - 1)
		data->stack_a[i++] = new_stack[j++];
	if (data->len_a)
		data->len_a--;
	write(1, "pb\n", 3);
	free(new_stack);
	free(stack_b);
}

void	op_pa_aux(t_temp *data, int i, int j, int *stack_a)
{
	if (!data->len_a)
	{
		data->stack_a[0] = data->stack_b[0];
		data->len_a++;
	}
	else if (!data->len_b)
	{
		return ;
	}
	else
	{
		i = 0;
		j = 0;
		while (i < data->len_a)
			stack_a[i++] = data->stack_a[j++];
		i = 1;
		j = 0;
		data->len_a++;
		while (i < data->len_a)
			data->stack_a[i++] = stack_a[j++];
		data->stack_a[0] = data->stack_b[0];
	}
}

void	pa(t_temp *data)
{
	int	*new_stack;
	int	*stack_a;
	int	i;
	int	j;

	i = 0;
	j = 1;
	new_stack = malloc(sizeof(int) * data->len_b);
	stack_a = malloc(sizeof(int) * data->len_a);
	op_pa_aux(data, i, j, stack_a);
	while (i < data->len_b - 1)
		new_stack[i++] = data->stack_b[j++];
	i = 0;
	j = 0;
	while (i < data->len_b - 1)
		data->stack_b[i++] = new_stack[j++];
	if (data->len_b)
		data->len_b--;
	write(1, "pa\n", 3);
	free(new_stack);
	free(stack_a);
}
