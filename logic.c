#include "includes/push_swap.h"

void	three_aux(t_temp *data)
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
	else if (len == 3 && check_sorted(data->stack_a, data->len_a))
		three_aux(data);
}

int	sort_and_pivot(t_temp *data, int len)
{
	int	i;
	int	j;
	int	*sort_temp;
	int	pivot;

	i = 0;
	j = 0;
	sort_temp = malloc(sizeof(int) * data->len_a);
	if (!sort_temp)
		return (0);
	while (i < len)
		sort_temp[i++] = data->stack_a[j++];
	quicksort(sort_temp, data->len_a);
	pivot = find_pivot(sort_temp, len);
	free(sort_temp);
	return (pivot);
}

void	four_to_hundred(t_temp *data, int pivot)
{
	while (check_pivot(data, pivot) && data->len_a > 3)
	{
		if (data->stack_a[0] >= pivot)
			ra(data);
		else if (data->stack_a[0] < pivot)
			pb(data);
	}
	if (data->len_a > 3 && data->stack_a[0] != 0)
	{
		pivot = sort_and_pivot(data, data->len_a);
		four_to_hundred(data, pivot);
	}	
}

void	four_to_hundred_cont(t_temp *data)
{
	int	where;

	where = ((data->len_b - 1) / 2);
	if (find_max(data) == 0)
	{
		if (data->stack_b[0] > data->stack_a[0])
		{
			pa(data);
			sa(data);
			return ;
		}
		pa(data);
	}
	else if (find_max(data) <= where && find_max(data) > 0)
		rb(data);
	else if (find_max(data) > where && find_max(data) > 0)
		rrb(data);
}
