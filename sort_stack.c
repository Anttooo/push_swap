#include "push_swap.h"

void	print_stacks(t_stacks *stacks);
int		is_sorted(t_stacks *stacks);
void	print_stats(t_stacks *stacks);
void	print_result(t_stacks *stacks);

void	sort_stack(t_stacks *stacks)
{
	int	i;

	i = 0;
	// Create stack B
	stacks->b = (t_list_item *)malloc(stacks->len * sizeof(t_list_item));
	if (stacks->b == NULL)
	{
		freemem(stacks);
		exit(1);
	}
	// Print stacks in the beginning
	ft_printf("Original stacks:\n");
	print_stacks(stacks);
	// Keep looping the sort function while it is not sorted
	push_all_to_b(stacks);
	while (is_sorted(stacks) != 1 && stacks->split < stacks->nr_of_splits + 1)
		sort_b(stacks);
	print_result(stacks);
	print_stats(stacks);
	// Print stacks in the end
	print_stacks(stacks);
}

int	is_sorted(t_stacks *stacks)
{
	int	i;

	i = 0;
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
	if (is_sorted(stacks) == 1 && stacks->a_len == stacks->org_len)
		ft_printf("SORTED in %d moves!\n", stacks->move_count);
	else
		ft_printf("Was not sorted in %d moves!\n", stacks->move_count);
}

void	print_stats(t_stacks *stacks)
{
	ft_printf("Moves used: \nRotate a: %d (%d%%)\nRotate b: %d\nRotate both: %d\n", stacks->moves.rotate_a, (stacks->moves.rotate_a * 100 / stacks->move_count ), stacks->moves.rotate_b, stacks->moves.rotate_both);
	ft_printf("Reverse rotate a:%d\nReverse rotate b: %d (%d%%)\nReverse rotate both: %d\n", stacks->moves.reverse_rotate_a, stacks->moves.reverse_rotate_b, (stacks->moves.reverse_rotate_b * 100 / stacks->move_count), stacks->moves.reverse_rotate_both);
	ft_printf("Swap a:%d\nSwap b: %d (%d%%)\nSwap both: %d\n", stacks->moves.swap_a, stacks->moves.swap_b, (stacks->moves.swap_b * 100 / stacks->move_count), stacks->moves.swap_both);
	ft_printf("Push a:%d\nPush b: %d\n", stacks->moves.push_a, stacks->moves.push_b);
}

