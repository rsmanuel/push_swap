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
		three_aux(data, len);
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
	int max;

	i = data->len_b;
	max = data->stack_b[i - 1];
	i--;
	while (i > 0)
	{
		if (data->stack_b[i - 1] > max)
		{
			max = data->stack_b[i - 1];
		}
		i--;
	}
	return (max);
}

void    four_to_hundred(t_temp *data, int len)
{
	int *sort_temp;
	int pivot;
	int i;
	int j;
	int max;

	i = 0;
	j = 0;
	sort_temp = malloc(sizeof(int) * data->len_a);
	if (!sort_temp)
		return ;
	while (i < len)
		sort_temp[i++] = data->stack_a[j++];
	i = 0;
	quicksort(sort_temp, data->len_a);
	pivot = find_pivot(sort_temp, len);
	while(data->len_a != 3)
	{
		if(data->stack_a[i] < pivot && data->stack_a[i] != pivot)
		{
			pb(data);
			i = 0;
		}
		else if (data->stack_a[i] > pivot && data->stack_a[i] != pivot)
			i++;
		i++;
	}
	two_and_three(data, data->len_a);
	max = find_max(data);
	printf("!!!%d!!!\n", max);
}
