#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>

typedef struct s_temp
{
    int len_a;
    int len_b;
    int *stack_a;
    int *stack_b;
}   t_temp;

void op_s(int *stack_a, int len);
void op_rr(int *stack_a, int len);
void op_r(int *stack_a, int len);
int *create_stackb(int len);
int *op_pb(int *stack_a, int len, t_temp *data);

#endif