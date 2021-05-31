#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct  s_stack
{
    int data;
    struct s_stack *next;
    struct s_stack *prev;
} 				t_stack;

#endif