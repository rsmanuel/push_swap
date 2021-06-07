#include "includes/push_swap.h"
#include <stdio.h>

void	test(int *stack_a, int ac, int i)
{
		i = 0;
		while(i < ac - 1)
		{
			printf("[%d]\n", stack_a[i]);
			i++;
		}
}

int  *quicksort(int *sort, int i)
{
	int ac;
	int average;

	ac = i;
	average = 0;
	while (--i > 0)
    {
		if (sort[i] < sort[i - 1])
		{
			ft_swap_int(&sort[i], &sort[i - 1]);
            quicksort(sort, ac);
        }
    }
	return (sort);
}

int check_errors(int *stack, int num, int i, char *av)
{
	int j;

	j = 0;
	while (--i > 0)
	{
		if (stack[i] == num || !ft_atoi(av))
		{
			write(1, "Error\n", 6);
			return (0);
		}
	}
	return (1);
}

int main(int ac, char **av)
{
    int *stack;
	int i;
	int	*demo;

	i = 0;
    if (ac > 1)
	{
        stack = (int *)malloc(sizeof(int) * (ac - 1));
		demo = (int *)malloc(sizeof(int) * (ac - 1));
		while(*++av)
		{
			stack[i] = ft_atoi(*av);
			if (!check_errors(stack, stack[i], i, *av))
				return(1);
			i++;
		}
		demo = quicksort(stack, ac - 1);
		test(demo, ac, i);
		return (0);
	}
	else
		return (1);
}	