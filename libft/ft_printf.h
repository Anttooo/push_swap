/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:52:18 by oanttoor          #+#    #+#             */
/*   Updated: 2022/11/15 15:52:21 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<unistd.h>
# include	<stdarg.h>
# include	"libft.h"

int		ft_printf(const char *str, ...);
void	handle_c(char c, int *count);
void	handle_s(char *str, int *count);
void	handle_p(void *p, int *count);
void	handle_d(int n, int *count);
void	handle_u(unsigned int n, int *count);
void	handle_lower_x(unsigned int dec, int *count);
void	handle_upper_x(unsigned int dec, int *count);

#endif
