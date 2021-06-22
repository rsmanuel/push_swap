#include "includes/push_swap.h"
#include <stdio.h>

void	op_s(int *stack)
{
	ft_swap_int(&stack[0], &stack[1]);
}

void	op_rr(int *stack, int len)
{
	int	*tmp_stack;
	int	i;
	int	j;
	int	last;

	i = 1;
	j = 0;
	tmp_stack = malloc(sizeof(int) * len);
	if (!tmp_stack)
		return ;
	last = stack[len - 1];
	while (j < len - 1)
		tmp_stack[i++] = stack[j++];
	i = 0;
	j = 0;
	while (i < len)
		stack[i++] = tmp_stack[j++];
	stack[0] = last;
	free(tmp_stack);
}

void	op_r(int *stack, int len)
{
	int	i;
	int	*tmp_stack;
	int	j;
	int	first;

	j = 1;
	i = 0;
	tmp_stack = malloc(sizeof(int) * len);
	if (!tmp_stack)
		return ;
	first = stack[0];
	while (i < len - 1)
		tmp_stack[i++] = stack[j++];
	i = 0;
	j = 0;
	while (i < len - 1)
		stack[i++] = tmp_stack[j++];
	stack[len - 1] = first;
	free(tmp_stack);
}
