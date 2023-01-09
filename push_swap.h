
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_list_item
{
	int	value;
	int	index;
	int	distance;
}		t_list_item;

typedef struct s_moves
{
	int	push_a;
	int	push_b;
	int	reverse_rotate_a;
	int	reverse_rotate_b;
	int	reverse_rotate_both;
	int	rotate_a;
	int	rotate_b;
	int	rotate_both;
	int	swap_a;
	int	swap_b;
	int	swap_both;
}		t_moves;

typedef struct s_stacks 
{
	t_list_item	*a;
	t_list_item	*b;
	t_moves		moves;
	int			len;
	int			b_len;
	int			a_len;
	int			org_len;
	int			move_count;
	int			max;
	int			min;
	int			decile;
	int			upper_limit;
	int			lower_limit;
	int			splits;
}		t_stacks;

// add function definitions here
void	sort_stack(t_stacks *stacks);
void	freemem(t_stacks *stacks);
void	sort_v1(t_stacks *stacks);
void	sort_b(t_stacks *stacks);

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
