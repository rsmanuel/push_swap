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
    int *tmp_stack_b;
    int top_b;
    int top_a;
}   t_temp;

void op_s(int *stack_a);
void op_rr(int *stack_a, int len);
void op_r(int *stack_a, int len);
void op_pb(t_temp *data);
int *create_stackb(int len);
void test(int *stack_a, int ac);
void op_pa(t_temp *data);

#endif