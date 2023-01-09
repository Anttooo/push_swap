#include "push_swap.h"

void	print_stacks(t_stacks *stacks);
int		is_sorted(t_stacks *stacks);

void	sort_stack(t_stacks *stacks)
{
	int	i;

	i = 0;
	stacks->b = (int *)malloc(stacks->len * sizeof(int));
	if (stacks->b == NULL)
	{
		freemem(stacks);
		exit(1);
	}
	ft_printf("Original stacks:\n");
	print_stacks(stacks);
	// while (!(is_sorted(stacks) == 1 && stacks->a_len == stacks->org_len))
	while (i < 100)
	{
		sort_v1(stacks);
		i++;
	}
	if (is_sorted(stacks) == 1 && stacks->a_len == stacks->org_len)
		ft_printf("SORTED in %d moves!\n", i);
	else
		ft_printf("Was not sorted in %d moves!\n", i);
	print_stacks(stacks);
}

int	is_sorted(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->a_len - 1)
	{
		if (stacks->a[i] < stacks->a[i + 1])
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
		ft_printf("%d ", stacks->a[i]);
		i++;
	}
	ft_printf("\n");
	i = 0;
	ft_printf("STACK B: ");
	while (i < stacks->b_len)
	{
		ft_printf("%d ", stacks->b[i]);
		i++;
	}
	ft_printf("\n");
}
