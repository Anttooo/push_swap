/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:01:57 by oanttoor          #+#    #+#             */
/*   Updated: 2022/10/24 16:01:58 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	check_input_values(const char *hs, const char *str, size_t len);
static char	*get_return_value(const char *hs, const char *str, size_t len);
static char	*find_match_location(const char *hs, const char *str, size_t len);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		correct_input;
	char	*match_location;

	correct_input = check_input_values(haystack, needle, len);
	if (correct_input == 0)
		return (get_return_value(haystack, needle, len));
	else
		match_location = find_match_location(haystack, needle, len);
	return (match_location);
}

// returns 1 if the values are ok and 0 if there was an issue
static int	check_input_values(const char *hs, const char *str, size_t len)
{
	size_t	str_len;
	size_t	hs_len;

	if (len == 0)
		return (0);
	str_len = (size_t)ft_strlen((char *)str);
	hs_len = (size_t)ft_strlen((char *)hs);
	if (str_len == 0)
		return (0);
	if (hs_len == 0)
		return (0);
	return (1);
}

static char	*get_return_value(const char *hs, const char *str, size_t len)
{
	size_t	str_len;
	size_t	hs_len;

	if (hs == NULL)
		return (NULL);
	if (str == NULL)
		return (NULL);
	str_len = (size_t)ft_strlen((char *)str);
	hs_len = (size_t)ft_strlen((char *)hs);
	if (str_len == 0)
		return ((char *)hs);
	if (hs_len == 0)
		return (NULL);
	if (len == 0)
		return (NULL);
	return (NULL);
}

static char	*find_match_location(const char *hs, const char *str, size_t len)
{
	int		i;
	size_t	str_len;

	str_len = (size_t)ft_strlen((char *)str);
	i = 0;
	while ((i + str_len) <= len)
	{
		if (ft_strncmp((hs + i), str, str_len) == 0)
			return ((char *)(hs + i));
		else
			i++;
	}
	return (NULL);
}
