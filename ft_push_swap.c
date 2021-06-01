#include "includes/push_swap.h"
#include <stdio.h>

/*void	test(int *stack_a, int ac, int i)
{
	printf("after ra:\n");
		stack_a = op_r(stack_a, ac - 1);
		i = 0;
		while(i < ac - 1)
		{
			printf("[%d]\n", stack_a[i]);
			i++;
		}
}*/

/*void quicksort(int *sort, int i)
{
	int ac;

	ac = i;
    while (sort[i] != '\0')
    {
        //if (sort[i] < sort[i - 1])
		//{
			ft_swap_int(&sort[i], &sort[i - 1]);
            //quicksort(sort, ac);
        //}
        i--;
    }
}*/

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

	i = 0;
    if (ac > 1)
	{
        stack = (int *)malloc(sizeof(int) * (ac - 1));
		while(*++av)
		{
			stack[i] = ft_atoi(*av);
			if (!check_errors(stack, stack[i], i, *av))
				return(1);
			printf("[%d]\n", stack[i]);
			i++;
		}
		//printf("{{%d}}", stack[ac - 2]);
		//quicksort(stack, ac - 2);
		//test(stack, ac, i);
		return (0);
	}
	else
		return (1);
}	