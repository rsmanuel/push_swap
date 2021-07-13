#include "includes/push_swap.h"
#include <stdio.h>

void	main_continue(t_temp *data, int len)
{
	int where;

	where = 0;
	if (len == 2 || len == 3)
		two_and_three(data, len);
	else if (len > 3 && len < 101)
	{
		four_to_hundred(data, sort_and_pivot(data, data->len_a));
		two_and_three(data, data->len_a);
		while (data->len_b > 0)
			four_to_hundred_cont(data);
	}
	else if (len > 100)
	{
		four_to_hundred(data, sort_and_pivot(data, data->len_a));
		two_and_three(data, data->len_a);
		while (data->len_b > 0)
			four_to_hundred_cont(data);
	}
}

void	init_struct(int *stack, int *stack_b, int ac)
{
	t_temp	*data;

	data = malloc(sizeof(t_temp));
	data->ac = ac;
	data->len_a = ac;
	data->len_b = 0;
	data->stack_a = stack;
	data->stack_b = stack_b;
	main_continue(data, ac);
	free(data);
}

int check_errors_aux(char *arg)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if(arg[i] == '-')
			i++;
		if (!ft_isdigit(arg[i]))
		{
			write(2, "Error\n", 6);
			return(1);
		}
		i++;
	}
	return (0);
}

int check_errors(int *stack, int len)
{
    int i;
    int j;

    i = 0;
    j = 1;
    while (i < len - 1)
    {
        if(stack[i] > stack[i + 1])
            break;
        i++;
    }
    if (i == (len - 1))
        return (1);
    i = 0;
    while (i < len - 1)
    {
        j = 0;
        while (j < len)
        {
            if (j == i)
                j++;
            if (stack[j] == stack[i])
			{
				write(2, "Error\n", 6);
                return(1);
			}
            j++;
        }
        i++;
    }
    return(0);
}

int	check_sorted(int *stack, int ac)
{
	int i;

	i = ac;
	while (i > 0)
	{
		if (stack[i] < stack[i - 1])
			return (1);
		i--;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	*stack;
	int	*stack_b;
	int	i;

	i = 0;
	if (ac > 1)
	{
		stack = (int *)malloc(sizeof(int) * (ac - 1));
		stack_b = (int *)malloc(sizeof(int) * (ac - 1));
		if (!stack || !stack_b)
			return (1);
		while (*++av)
		{
			if (check_errors_aux(*av))
			{
				free(stack);
				free(stack_b);
				return (1);
			}
			stack[i] = ft_atoi(*av);
			i++;
		}
		if (check_errors(stack, ac - 1))
		{
			free(stack);
			free(stack_b);
			return (1);
		}
		init_struct(stack, stack_b, ac - 1);
		free(stack);
		free(stack_b);
		return (0);
	}
	else
		return (1);
}
