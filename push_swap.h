
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_stacks 
{
	int	*a;
	int	*b;
	int	len;
	int	b_len;
	int	a_len;
	int	org_len;
}		t_stacks;

// add function definitions here
void	sort_stack(t_stacks *stacks);
void	freemem(t_stacks *stacks);
void	sort_v1(t_stacks *stacks);

// Push swap language instructions, not included in the final version
void	push_to_a(t_stacks *stacks);
void	push_to_b(t_stacks *stacks);
void	swap_a(t_stacks *stacks);
void	swap_b(t_stacks *stacks);
void	swap_both(t_stacks *stacks);
void	rotate_a(t_stacks *stacks);
void	rotate_b(t_stacks *stacks);
void	rotate_both(t_stacks *stacks);
void	reverse_rotate_a(t_stacks *stacks);
void	reverse_rotate_b(t_stacks *stacks);
void	reverse_rotate_both(t_stacks *stacks);

#endif
