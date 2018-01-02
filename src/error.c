/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 17:38:03 by sjones            #+#    #+#             */
/*   Updated: 2018/01/01 17:55:38 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_error(char c)
{
	return (c == 'a' || c == '*' || c == 'e' || c == 'f' || c == 'g' ||
			c == 'L' || c == 'n' || c == 'A') ? (1) : (0);
}

void	get_error(t_print *p)
{
	int	error;

	error = (int)va_arg(p->args, int);
	p->i++;
	write(p->fd, "error", 5);
}
