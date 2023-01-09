#include "../push_swap.h"

void	reverse_rotate_both(t_stacks *stacks)
{
	reverse_rotate_a(stacks);
	reverse_rotate_b(stacks);
}