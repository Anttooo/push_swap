/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:05:03 by oanttoor          #+#    #+#             */
/*   Updated: 2022/11/07 13:05:06 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
 
 # ifndef BUFFER_SIZE
 # define BUFFER_SIZE 1
 # endif

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>

typedef struct buffer_cache
{
	char	*arr;
	char	*temp_cache;
}		t_cache;

/* 
* eol = end of line index
* eol_found = end of line was found from the buffer
* eof = end of file reached
*/
typedef struct buffer
{
	int		index;
	int		eol;
	char	*arr;
	int		eof;
	int		read_len;
	int		eol_found;
}		t_buffer;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	gnl_freemem(t_buffer *buffer, t_cache *cache);

#endif
