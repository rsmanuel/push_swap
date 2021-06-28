#include "includes/push_swap.h"
#include <stdio.h>

void	three_aux(t_temp *data, int len)
{
	if (data->stack_a[0] > data->stack_a[1]
		&& data->stack_a[2] > data->stack_a[1]
		&& data->stack_a[2] > data->stack_a[0])
		sa(data);
	else if (data->stack_a[1] < data->stack_a[0]
		&& data->stack_a[2] < data->stack_a[1]
		&& data->stack_a[2] < data->stack_a[0])
	{
		sa(data);
		rra(data);
	}
	else if (data->stack_a[0] > data->stack_a[1]
		&& data->stack_a[0] > data->stack_a[2]
		&& data->stack_a[2] > data->stack_a[1])
		ra(data);
	else if (data->stack_a[1] > data->stack_a[0]
		&& data->stack_a[1] > data->stack_a[2]
		&& data->stack_a[2] > data->stack_a[0])
	{
		sa(data);
		ra(data);
	}
	else
		rra(data);
}

void	two_and_three(t_temp *data, int len)
{
	if (len == 2)
	{
		if (data->stack_a[0] > data->stack_a[1])
			sa(data);
	}
	else if (len == 3)
		three_aux(data, len);
}

void    four_and_five(t_temp *data, int len)
{
    while(data->len_a != 3)
		pb(data);
	two_and_three(data, data->len_a);
	while (data->len_a != len)
		pa(data);
	test_print_stack(data);
}
