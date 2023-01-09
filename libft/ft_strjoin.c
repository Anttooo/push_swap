/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:08:59 by oanttoor          #+#    #+#             */
/*   Updated: 2022/10/24 16:09:00 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	total_len = s1_len + s2_len + 1;
	joined = (char *)malloc((total_len) * sizeof(char));
	if (joined == NULL)
		return (NULL);
	ft_strlcpy(joined, (char *)s1, total_len);
	ft_strlcat(joined, (char *)s2, total_len);
	return (joined);
}
