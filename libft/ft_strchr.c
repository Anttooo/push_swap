/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:00:30 by oanttoor          #+#    #+#             */
/*   Updated: 2022/10/24 16:00:33 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	ptr = (char *)s;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&ptr[i]);
		else
			i++;
	}
	if ((char)c == '\0')
		return (&ptr[i]);
	return (0);
}
