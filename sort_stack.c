#include "push_swap.h"

void	print_stacks(t_stacks *stacks);
int		is_sorted(t_stacks *stacks);
void	print_result(t_stacks *stacks);
void	sort_stack(t_stacks *stacks)
{
	int	i;

	i = 0;
	// Create stack B
	ft_printf("stacks->org_len: %d\n", stacks->org_len);
	stacks->b = (t_list_item *)malloc(stacks->org_len * sizeof(t_list_item));
	if (stacks->b == NULL)
	{
		freemem(stacks);
		exit(1);
	}
	// Print stacks in the beginning
	ft_printf("Original stacks:\n");
	print_stacks(stacks);
	// Move all but three values to b
	// ft_printf("NEXT: prepare_b\n");
	prepare_b(stacks);
	// ft_printf("NEXT: sort_a\n");
	sort_a(stacks);
	// ft_printf("NEXT: sort_b\n");
	while (is_sorted(stacks) != 1 && i < 1)
	{
		sort_b(stacks);
		i++;
	}
	ft_printf("Sorted stacks:\n");
	update_total_move_count(&stacks->move_counter);
	print_stacks(stacks);
	print_result(stacks);
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

void	print_stacks(t_stacks *stacks)
{
	int	i;

	i = 0;
	ft_printf("STACK A: ");
	while (i < stacks->a_len)
	{
		ft_printf("%d ", stacks->a[i].value);
		i++;
	}
	ft_printf("\n");
	i = 0;
	ft_printf("STACK B: ");
	while (i < stacks->b_len)
	{
		ft_printf("%d ", stacks->b[i].value);
		i++;
	}
	ft_printf("\n");
}

void	print_result(t_stacks *stacks)
{
	update_total_move_count(&stacks->move_counter);
	if (is_sorted(stacks) == 1 && stacks->a_len == stacks->org_len)
		ft_printf("\nSORTED in %d moves!\n", stacks->move_counter.total);
	else
		ft_printf("NOT SORTED in %d moves!\n", stacks->move_counter.total);
}

void	update_total_move_count(t_moves *move_counter)
{
	move_counter->total = 0;
	move_counter->total = move_counter->total + move_counter->push_a;
	move_counter->total = move_counter->total + move_counter->push_b;
	move_counter->total = move_counter->total + move_counter->reverse_rotate_a;
	move_counter->total = move_counter->total + move_counter->reverse_rotate_b;
	move_counter->total = move_counter->total + move_counter->reverse_rotate_both;
	move_counter->total = move_counter->total + move_counter->rotate_a;
	move_counter->total = move_counter->total + move_counter->rotate_b;
	move_counter->total = move_counter->total + move_counter->rotate_both;
	move_counter->total = move_counter->total + move_counter->swap_a;
	move_counter->total = move_counter->total + move_counter->swap_b;
	move_counter->total = move_counter->total + move_counter->swap_both;
}

void	update_total_move_count_for_index(t_stacks *stacks, int i)
{
	stacks->b[i].required_moves.total = 0;
	stacks->b[i].required_moves.total = stacks->b[i].required_moves.total + stacks->b[i].required_moves.push_a;
	stacks->b[i].required_moves.total = stacks->b[i].required_moves.total + stacks->b[i].required_moves.push_b;
	stacks->b[i].required_moves.total = stacks->b[i].required_moves.total + stacks->b[i].required_moves.reverse_rotate_a;
	stacks->b[i].required_moves.total = stacks->b[i].required_moves.total + stacks->b[i].required_moves.reverse_rotate_b;
	stacks->b[i].required_moves.total = stacks->b[i].required_moves.total + stacks->b[i].required_moves.reverse_rotate_both;
	stacks->b[i].required_moves.total = stacks->b[i].required_moves.total + stacks->b[i].required_moves.rotate_a;
	stacks->b[i].required_moves.total = stacks->b[i].required_moves.total + stacks->b[i].required_moves.rotate_b;
	stacks->b[i].required_moves.total = stacks->b[i].required_moves.total + stacks->b[i].required_moves.rotate_both;
	stacks->b[i].required_moves.total = stacks->b[i].required_moves.total + stacks->b[i].required_moves.swap_a;
	stacks->b[i].required_moves.total = stacks->b[i].required_moves.total + stacks->b[i].required_moves.swap_b;
	stacks->b[i].required_moves.total = stacks->b[i].required_moves.total + stacks->b[i].required_moves.swap_both;
}

