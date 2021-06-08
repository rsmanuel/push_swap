#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>

typedef struct s_temp
{
    int temp;
    int b_top;
    int a_top;
}   t_temp;

int	*op_s(int *stack_a, int len);
int *op_rr(int *stack_a, int len);
int *op_r(int *stack_a, int len);
int *create_stackb(int len);
int *op_p(int *stack_from, int *stack_to, int len);

#endif