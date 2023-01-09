/* ************************************************************************** */
/**/
/*:::  ::::::::   */
/*   ft_strtrim.c   :+:  :+::+:   */
/*+:+ +:+ +:+ */
/*   By: oanttoor <marvin@42.fr>+#+  +:+   +#+*/
/*+#+#+#+#+#+   +#+   */
/*   Created: 2022/10/24 16:09:09 by oanttoor  #+##+# */
/*   Updated: 2022/10/24 16:09:10 by oanttoor ###   ########.fr   */
/**/
/* ************************************************************************** */

#include "./libft.h"

static int	check_letter(char *set, char letter);
static int	find_start(char *s1, char *set);
static int	find_end(char *s1, char *set);
static void	write_trim(const char *s1, char *trimmed, int start, int new_len);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		start;
	int		end;
	int		new_len;

	if (!s1 || !set)
		return (NULL);
	start = find_start((char *)s1, (char *)set);
	end = find_end((char *)s1, (char *)set);
	new_len = ft_strlen((char *)s1) - start - end;
	if (new_len <= 0)
		new_len = 0;
	trimmed = (char *)malloc((new_len + 1) * sizeof(char));
	if (trimmed == NULL)
		return (NULL);
	if (new_len == 0)
		trimmed[0] = '\0';
	else
		write_trim((char *)s1, trimmed, start, new_len);
	return (trimmed);
}

static int	find_start(char *s1, char *set)
{
	int	counter;
	int	i;
	int	max_len;

	max_len = ((int)ft_strlen((char *)s1) - 1);
	i = 0;
	counter = 0;
	while (check_letter(set, s1[i]) == 1 && i < max_len)
	{
		i++;
		counter++;
	}
	return (counter);
}

static int	check_letter(char *set, char letter)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == letter)
			return (1);
		else
			i++;
	}
	return (0);
}

static int	find_end(char *s1, char *set)
{
	int	counter;
	int	i;

	i = (int)ft_strlen((char *)s1) - 1;
	counter = 0;
	while (check_letter(set, s1[i]) == 1 && i > 0)
	{
		i--;
		counter++;
	}
	return (counter);
}

void	write_trim(const char *s1, char *trimmed, int start, int new_len)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)s1;
	while (i < new_len)
	{
		*(trimmed + i) = ptr[start];
		i++;
		start++;
	}
	*(trimmed + i) = '\0';
}
