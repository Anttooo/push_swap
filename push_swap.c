#include "push_swap.h"

void	read_stack(int argc, char **argv, t_stacks *stacks);
void	freemem(t_stacks *stacks);

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	stacks.b = NULL;
	stacks.a = NULL;
	stacks.a_len = argc - 1;
	stacks.b_len = 0;
	stacks.org_len = argc - 1;
	stacks.lower_limit = INT32_MAX;
	stacks.upper_limit = INT32_MIN;
	stacks.splits = 4;
	stacks.moves.push_a = 0;
	stacks.moves.push_b = 0;
	stacks.moves.reverse_rotate_a = 0;
	stacks.moves.reverse_rotate_b = 0;
	stacks.moves.reverse_rotate_both = 0;
	stacks.moves.rotate_a = 0;
	stacks.moves.rotate_b = 0;
	stacks.moves.rotate_both = 0;
	stacks.moves.swap_a = 0;
	stacks.moves.swap_b = 0;
	stacks.moves.swap_both = 0;
	ft_printf("argc: %d \n", argc); // ONLY FOR DEBUG PURPOSES - REMOVE BEFORE EVAL
	read_stack(argc, argv, &stacks);
	// TODO: add sort check before sorting
	sort_stack(&stacks);
	freemem(&stacks);
	return (0);
}

void	read_stack(int argc, char **argv, t_stacks *stacks)
{
	int	i;

	i = 0;
	stacks->max = INT32_MIN;
	stacks->min = INT32_MAX;
	// TODO: ADD HANDLING OF VALUES OUTSIDE OF MAX_INT AND MIN_INT
	stacks->a = (t_list_item *)malloc(argc * sizeof(t_list_item));
	if (stacks->a == NULL)
		freemem(stacks);
	while (i < argc - 1)
	{
		stacks->a[i].value = ft_atoi(argv[i + 1]);
		if (stacks->a[i].value == 0 && *argv[i + 1] != (char)'0') // IF THE VALUE CAN'T BE READ, ATOI RETURNS 0 SO WE NEED TO DISTINGUISH BETWEEN 0 AND '0'
		{
			ft_printf("Error\n");
			freemem(stacks);
			exit(1);
		}
		if (stacks->a[i].value > stacks->max)
			stacks->max = stacks->a[i].value;
		if (stacks->a[i].value < stacks->min)
			stacks->min = stacks->a[i].value;
		i++;
	}
}

void	freemem(t_stacks *stacks)
{
	if (stacks->a != NULL)
	{
		free(stacks->a);
		stacks->a = NULL;
	}
	if (stacks->b != NULL)
	{
		free(stacks->b);
		stacks->b = NULL;
	}
}
