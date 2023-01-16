#include "push_swap.h"

int		is_sorted(t_stacks *stacks);
void	initialise_stack_b(t_stacks *stacks);

void	sort_stack(t_stacks *stacks)
{
	initialise_stack_b(stacks);
	prepare_b(stacks);
	sort_a(stacks);
	while (is_sorted(stacks) != 1)
		complete_next_move(stacks);
	update_total_move_count(&stacks->move_counter);
	print_result(stacks); // TODO: remove this before submitting
}

void	initialise_stack_b(t_stacks *stacks)
{
	stacks->b = (t_list_item *)malloc(stacks->org_len * sizeof(t_list_item));
	if (stacks->b == NULL)
	{
		freemem(stacks);
		exit(1);
	}
}

int	is_sorted(t_stacks *stacks)
{
	int	i;

	i = 0;
	if (stacks->a_len < stacks->org_len)
		return (0);
	while (i < stacks->a_len - 1)
	{
		if (stacks->a[i].value < stacks->a[i + 1].value)
			i++;
		else
			return(0);
	}
	return (1);
}

void	update_total_move_count(t_moves *move_counter)
{
	move_counter->total = 0;
	move_counter->total = move_counter->total + move_counter->push_a;
	move_counter->total = move_counter->total + move_counter->push_b;
	move_counter->total = move_counter->total + move_counter->rra;
	move_counter->total = move_counter->total + move_counter->rrb;
	move_counter->total = move_counter->total + move_counter->rrr;
	move_counter->total = move_counter->total + move_counter->ra;
	move_counter->total = move_counter->total + move_counter->rb;
	move_counter->total = move_counter->total + move_counter->rr;
	move_counter->total = move_counter->total + move_counter->swap_a;
	move_counter->total = move_counter->total + move_counter->swap_b;
	move_counter->total = move_counter->total + move_counter->swap_both;
}

void	update_total_move_count_for_index(t_stacks *stacks, int i)
{
	stacks->b[i].required_moves.total = 0;
	stacks->b[i].required_moves.total = stacks->b[i].required_moves.total + stacks->b[i].required_moves.push_a;
	stacks->b[i].required_moves.total = stacks->b[i].required_moves.total + stacks->b[i].required_moves.push_b;
	stacks->b[i].required_moves.total = stacks->b[i].required_moves.total + stacks->b[i].required_moves.rra;
	stacks->b[i].required_moves.total = stacks->b[i].required_moves.total + stacks->b[i].required_moves.rrb;
	stacks->b[i].required_moves.total = stacks->b[i].required_moves.total + stacks->b[i].required_moves.rrr;
	stacks->b[i].required_moves.total = stacks->b[i].required_moves.total + stacks->b[i].required_moves.ra;
	stacks->b[i].required_moves.total = stacks->b[i].required_moves.total + stacks->b[i].required_moves.rb;
	stacks->b[i].required_moves.total = stacks->b[i].required_moves.total + stacks->b[i].required_moves.rr;
	stacks->b[i].required_moves.total = stacks->b[i].required_moves.total + stacks->b[i].required_moves.swap_a;
	stacks->b[i].required_moves.total = stacks->b[i].required_moves.total + stacks->b[i].required_moves.swap_b;
	stacks->b[i].required_moves.total = stacks->b[i].required_moves.total + stacks->b[i].required_moves.swap_both;
}

