#include "includes/push_swap.h"
#include <stdio.h>

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

void quicksort(int *sort, int len)
{
	int count;
	int i;

	count = 0;
	i = len;
	while (--i > 0)
    {
		if (sort[i] < sort[i - 1])
		{
			ft_swap_int(&sort[i], &sort[i - 1]);
			count++; 
		}
	}
	if (count)
		quicksort(sort, len);
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

int find_pivot(int *sort, int len)
{
	int index;

	index = len / 2;
	return(sort[index]);
}

int find_max(t_temp *data)
{
	int i;
	int j;
	int max;

	i = 0;
	j = i;
	max = data->stack_b[i];
	while (data->stack_b[i++] && i < data->len_b)
	{
		if (data->stack_b[i] > max)
			j = i;
	}
	return (j);
}

int check_pivot(t_temp *data, int pivot)
{
	int i;

	i = 0;
	while(data->stack_a[i] && i < data->len_a)
	{
		if (data->stack_a[i] < pivot)
			return (1);
		i++;
	}
	return (0);
}

int sort_and_pivot(t_temp *data, int len)
{
	int i;
	int j;
	int *sort_temp;
	int pivot;

	i = 0;
	j = 0;
	sort_temp = malloc(sizeof(int) * data->len_a);
	if (!sort_temp)
		return (0);
	while (i < len)
		sort_temp[i++] = data->stack_a[j++];
	i = 0;
	quicksort(sort_temp, data->len_a);
	pivot = find_pivot(sort_temp, len);
	free(sort_temp);

	return (pivot);
}


void    four_to_hundred(t_temp *data, int pivot)
{
	while (check_pivot(data, pivot) && data->len_a > 3)
	{
		if (data->stack_a[0] >= pivot)
			ra(data);
		else if (data->stack_a[0] < pivot)
			pb(data);
	}
	if (data->len_a > 3)
	{
		pivot = sort_and_pivot(data, data->len_a);
		four_to_hundred(data, pivot);
	}	
}

int find_old_max(int old_max, t_temp *data)
{
	int i;

	i = 0;
	while(data->stack_a[i] && i < data->len_a)
	{
		if (data->stack_a[i] == old_max)
			return (1);
		i++;
	}
	return (0);
}

void four_to_hundred_cont(t_temp *data, int max)
{
	int where;

	where = ((data->len_b - 1) / 2);
	if (max == 0)
		pa(data);
	else if (max < where)
	{
		while (max != 0)
			rb(data);
		pa(data);
	}
	else if (max > where)
	{
		while (max != 0)
			rrb(data);
		pa(data);
	}
	if (data->len_b > 0)
		four_to_hundred_cont(data, max);
}