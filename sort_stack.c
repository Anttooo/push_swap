#include "push_swap.h"

void	print_stacks(t_stacks *stacks);
int		is_sorted(t_stacks *stacks);

void	sort_stack(t_stacks *stacks)
{
	int	i;

	i = 0;
	stacks->b = (t_list_item *)malloc(stacks->len * sizeof(t_list_item));
	if (stacks->b == NULL)
	{
		freemem(stacks);
		exit(1);
	}
	ft_printf("Original stacks:\n");
	print_stacks(stacks);
	// while (!(is_sorted(stacks) == 1 && stacks->a_len == stacks->org_len))
	while (is_sorted(stacks) != 1 && stacks->decile < stacks->splits)
		sort_v1(stacks);
	if (is_sorted(stacks) == 1 && stacks->a_len == stacks->org_len)
		ft_printf("SORTED in %d moves!\n", stacks->move_count);
	else
		ft_printf("Was not sorted in %d moves!\n", stacks->move_count);
		ft_printf("Moves used: \nRotate a: %d\nRotate b: %d\nRotate both: %d\n", stacks->moves.rotate_a, stacks->moves.rotate_b, stacks->moves.rotate_both);
		ft_printf("Reverse rotate a:%d\nReverse rotate b: %d\nReverse rotate both: %d\n", stacks->moves.reverse_rotate_a, stacks->moves.reverse_rotate_b, stacks->moves.reverse_rotate_both);
		ft_printf("Swap a:%d\nSwap b: %d\nSwap both: %d\n", stacks->moves.swap_a, stacks->moves.swap_b, stacks->moves.swap_both);
		ft_printf("Push a:%d\nPush b: %d\n", stacks->moves.push_a, stacks->moves.push_b);
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
