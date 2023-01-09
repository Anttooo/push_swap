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
	ft_printf("argc: %d \n", argc);
	read_stack(argc, argv, &stacks);
	sort_stack(&stacks);
	freemem(&stacks);
	return (0);
}

void	read_stack(int argc, char **argv, t_stacks *stacks)
{
	int	i;

	i = 0;
	stacks->a = (int *)ft_calloc(argc, sizeof(int));
	if (stacks->a == NULL)
		freemem(stacks);
	while (i < argc - 1)
	{
		stacks->a[i] = ft_atoi(argv[i + 1]);
		if (stacks->a[i] == 0 && *argv[i + 1] != (char)'0')
		{
			ft_printf("Error\n");
			freemem(stacks);
			exit(1);
		}
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
