#include "includes/push_swap.h"

void	quicksort(int *sort, int len)
{
	int	count;
	int	i;

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

int	find_pivot(int *sort, int len)
{
	int	index;

	index = len / 4;
	return (sort[index]);
}

int	find_max(t_temp *data)
{
	int	i;
	int	max;
	int	index;

	i = 0;
	max = data->stack_b[0];
	index = 0;
	while (i < data->len_b)
	{
		if (max <= data->stack_b[i])
		{
			index = i;
			max = data->stack_b[i];
		}
		i++;
	}
	return (index);
}

int	check_pivot(t_temp *data, int pivot)
{
	int	i;

	i = 0;
	while (i < data->len_a)
	{
		if (data->stack_a[i] < pivot)
			return (1);
		i++;
	}
	return (0);
}
