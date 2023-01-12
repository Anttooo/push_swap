#include "push_swap.h"

void	print_stacks(t_stacks *stacks);
int		is_sorted(t_stacks *stacks);
void	print_stats(t_stacks *stacks);
void	print_result(t_stacks *stacks);
void	calculate_total_moves(t_stacks *stacks);

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
	print_stacks(stacks);
	print_result(stacks);
	print_stats(stacks);
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
	calculate_total_moves(stacks);
	if (is_sorted(stacks) == 1 && stacks->a_len == stacks->org_len)
		ft_printf("\nSORTED in %d moves!\n", stacks->move_counter.total);
	else
		ft_printf("NOT SORTED in %d moves!\n", stacks->move_counter.total);
}

void	print_stats(t_stacks *stacks)
{
	calculate_total_moves(stacks);
	ft_printf("\nSTATISTICS \nRotate a: %d (%d%%)\nRotate b: %d\nRotate both: %d\n", stacks->move_counter.rotate_a, (stacks->move_counter.rotate_a * 100 / stacks->move_counter.total ), stacks->move_counter.rotate_b, stacks->move_counter.rotate_both);
	ft_printf("Reverse rotate a:%d\nReverse rotate b: %d (%d%%)\nReverse rotate both: %d\n", stacks->move_counter.reverse_rotate_a, stacks->move_counter.reverse_rotate_b, (stacks->move_counter.reverse_rotate_b * 100 / stacks->move_counter.total), stacks->move_counter.reverse_rotate_both);
	ft_printf("Swap a:%d\nSwap b: %d (%d%%)\nSwap both: %d\n", stacks->move_counter.swap_a, stacks->move_counter.swap_b, (stacks->move_counter.swap_b * 100 / stacks->move_counter.total), stacks->move_counter.swap_both);
	ft_printf("Push a:%d\nPush b: %d\n\n", stacks->move_counter.push_a, stacks->move_counter.push_b);
}

void	calculate_total_moves(t_stacks *stacks)
{
	stacks->move_counter.total = 0;
	stacks->move_counter.total = stacks->move_counter.total + stacks->move_counter.push_a;
	stacks->move_counter.total = stacks->move_counter.total + stacks->move_counter.push_b;
	stacks->move_counter.total = stacks->move_counter.total + stacks->move_counter.reverse_rotate_a;
	stacks->move_counter.total = stacks->move_counter.total + stacks->move_counter.reverse_rotate_b;
	stacks->move_counter.total = stacks->move_counter.total + stacks->move_counter.reverse_rotate_both;
	stacks->move_counter.total = stacks->move_counter.total + stacks->move_counter.rotate_a;
	stacks->move_counter.total = stacks->move_counter.total + stacks->move_counter.rotate_b;
	stacks->move_counter.total = stacks->move_counter.total + stacks->move_counter.rotate_both;
	stacks->move_counter.total = stacks->move_counter.total + stacks->move_counter.swap_a;
	stacks->move_counter.total = stacks->move_counter.total + stacks->move_counter.swap_b;
	stacks->move_counter.total = stacks->move_counter.total + stacks->move_counter.swap_both;
}

