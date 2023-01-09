/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:01:43 by oanttoor          #+#    #+#             */
/*   Updated: 2022/10/24 16:01:45 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	get_len(const char *s1, const char *s2, size_t n);
static int	find_difference(char *s1, char *s2, int len_to_check);

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	len_to_check;
	int		difference;

	if (n == 0)
		return (0);
	if (n > LONGG_MAX)
		n = LONGG_MAX;
	len_to_check = get_len(s1, s2, n);
	difference = find_difference((char *)s1, (char *)s2, len_to_check);
	return (difference);
}

static int	get_len(const char *s1, const char *s2, size_t n)
{
	size_t	s1_length;
	size_t	s2_length;

	s1_length = ft_strlen((char *)s1);
	s2_length = ft_strlen((char *)s2);
	if (s1_length >= n && s2_length >= n)
		return (n);
	else if (s1_length > s2_length)
		return (s1_length);
	else
		return (s2_length);
}

static int	find_difference(char *s1, char *s2, int len_to_check)
{
	int				i;
	int				dif;
	unsigned char	*unsigned_s1;
	unsigned char	*unsigned_s2;

	unsigned_s1 = (unsigned char *)s1;
	unsigned_s2 = (unsigned char *)s2;
	i = 0;
	dif = 0;
	while (i < len_to_check)
	{
		if (unsigned_s1[i] == unsigned_s2[i])
			i++;
		else if (unsigned_s1[i] == '\0' || unsigned_s2[i] == '\0')
		{
			dif = unsigned_s1[i] - unsigned_s2[i];
			return (dif);
		}
		else
		{
			dif = unsigned_s1[i] - unsigned_s2[i];
			return (dif);
		}
	}
	return (dif);
}
