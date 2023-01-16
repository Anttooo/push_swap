#include "push_swap.h"

void	initialise_move_counter(t_stacks *stacks);

void	initialise_data(t_stacks *stacks, int argc)
{
	stacks->b = NULL;
	stacks->a = NULL;
	stacks->a_len = argc - 1;
	stacks->b_len = 0;
	stacks->org_len = argc - 1;
	stacks->lower_limit = INT32_MAX;
	stacks->upper_limit = INT32_MIN;
	stacks->nr_of_splits = 2;
	stacks->split = 0;
	stacks->median = 0;
	stacks->zero_index = 0;
	stacks->printing_enabled = 0;
	initialise_move_counter(stacks);
}

void	initialise_move_counter(t_stacks *stacks)
{
	stacks->move_counter.push_a = 0;
	stacks->move_counter.push_b = 0;
	stacks->move_counter.rra = 0;
	stacks->move_counter.rrb = 0;
	stacks->move_counter.rrr = 0;
	stacks->move_counter.ra = 0;
	stacks->move_counter.rb = 0;
	stacks->move_counter.rr = 0;
	stacks->move_counter.swap_a = 0;
	stacks->move_counter.swap_b = 0;
	stacks->move_counter.swap_both = 0;
}