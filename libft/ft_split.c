/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:09:34 by oanttoor          #+#    #+#             */
/*   Updated: 2022/10/24 16:09:35 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	count_strings(char const *s, char c);
static void	write_split(char *dst, char *src, int index, int split_len);
static int	check_split_len(int	*x, char const *s, char c);
static int	write_splits(char **arr, char const *s, char c, int str_count);

char	**ft_split(char const *s, char c)
{
	int		str_count;
	char	**arr;

	if (!s)
		return (NULL);
	str_count = count_strings(s, c);
	arr = (char **)malloc((str_count + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	if (write_splits(arr, s, c, str_count) == 0)
		return (NULL);
	arr[str_count] = NULL;
	return (arr);
}

static int	count_strings(char const *s, char c)
{
	int	i;
	int	string_count;

	i = 0;
	string_count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			string_count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (string_count);
}

static int	write_splits(char **arr, char const *s, char c, int str_count)
{
	int		split_len;
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (i < str_count)
	{
		split_len = check_split_len(&x, s, c);
		arr[i] = (char *)malloc((split_len + 1) * sizeof(char));
		if (arr[i] == NULL)
		{
			i = 0;
			while (arr[i])
			{
				free(arr[i]);
				i++;
			}
			free (arr);
			return (0);
		}
		write_split(arr[i], (char *)s, x, split_len);
		i++;
	}
	return (1);
}

static int	check_split_len(int	*x, char const *s, char c)
{
	int	i;
	int	split_len;

	i = *x;
	split_len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		split_len++;
		i++;
	}
	*x = i;
	return (split_len);
}

static void	write_split(char *dst, char *src, int index, int split_len)
{
	int		i;
	int		src_index;
	char	*ptr;

	ptr = src;
	src_index = index - split_len;
	i = 0;
	while (i < split_len)
	{
		*(dst + i) = *(ptr + src_index);
		i++;
		src_index++;
	}
	*(dst + i) = '\0';
}
