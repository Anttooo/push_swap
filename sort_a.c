#include "push_swap.h"

int	is_abc(int a, int b, int c);
int	is_acb(int a, int b, int c);
int	is_bca(int a, int b, int c);
int	is_cab(int a, int b, int c);
int	is_bac(int a, int b, int c);
int	is_cba(int a, int b, int c);

void	sort_a(t_data *data)
{
	int	a;
	int	b;
	int	c;
	
	a = data->a[0].value;
	b = data->a[1].value;
	c = data->a[2].value;
	
	if (is_abc(a,b,c) == 1) // (1, 2, 3)
	{
		// already sorted do nothing
	}
	else if (is_acb(a,b,c) == 1) // (1, 3, 2)
	{
		reverse_rotate_a(data);
		swap_a(data);
	}
	else if (is_bca(a,b,c)) // (2, 3, 1)
	{
		reverse_rotate_a(data);
	}
	else if (is_cab(a,b,c)) // (3, 1, 2)
	{
		rotate_a(data);
	}
	else if (is_bac(a,b,c)) // (2, 1, 3)
	{
		swap_a(data);
	}
	else if (is_cba(a,b,c)) // (3, 2, 1)
	{
		rotate_a(data);
		swap_a(data);
	}
}

int	is_abc(int a, int b, int c) // 1,2,3
{
	if (a <= b && b <= c)
		return (1);
	else
		return (0);
}

int	is_acb(int a, int b, int c) // 1,3,2
{
	if (a <= b && c <= b && a <= c)
		return (1);
	else
		return (0);
}

int	is_bca(int a, int b, int c) // 2,3,1
{
	if (a <= b && c <= b)
		return (1);
	else
		return (0);
}

int	is_cab(int a, int b, int c) // 3,1,2
{
	if (b <= a && c <= a && b <= c)
		return (1);
	else
		return (0);
}

int	is_bac(int a, int b, int c) // 3,1,2
{
	if (b <= a && a <= c)
		return (1);
	else
		return (0);
}

int	is_cba(int a, int b, int c) // 3,2,1
{
	if (c <= b && b <= a)
		return (1);
	else
		return (0);
}