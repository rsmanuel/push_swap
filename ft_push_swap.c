#include "includes/push_swap.h"
#include <stdio.h>

void	test(int *stack_a, int ac)
{
		int i;

		i = 0;
		while(i < ac)
		{
			printf("[%d]\n", stack_a[i]);
			i++;
		}
}

void	main_continue(int *stack, int ac)
{
	t_temp *data;
	
	data->len_a = ac;
	data->len_b = 0;
	data->stack_a = stack;
}

int check_errors(int *stack, int num, int i, char *av)
{
	int j;

	j = 0;
	while (i-- > 0)
	{
		if (stack[i] == num || !ft_atoi(av))
		{
			write(2, "Error\n", 6);
			return (0);
		}
	}
	return (1);
}

int	check_sorted(int *stack, int ac)
{
	int i;
	
	i = ac - 1;
	while(i-- > 1)
	{
		if(stack[i] < stack[i - 1])
			return(1);
	}
	return (0);
}

int main(int ac, char **av)
{
    int *stack;
	int i;

	i = 0;
    if (ac > 1)
	{
        stack = (int *)malloc(sizeof(int) * (ac - 1));
		if (!stack)
			return(1);
		while(*++av)
		{
			stack[i] = ft_atoi(*av);
			if (!check_errors(stack, stack[i], i, *av))
				return(1);
			if(!check_sorted(stack, ac))
				return(1);
			i++;
		}
		main_continue(stack, ac - 1);
		return (0);
	}
	else
		return (1);
}