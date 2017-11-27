/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:00:53 by sjones            #+#    #+#             */
/*   Updated: 2017/11/27 13:00:54 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *fmt, ...)
{
	t_print		p;

	init_print(&p, 1, (char*)fmt);
	va_start(p.args, fmt);
	printf_meat(&p);
	va_end(p.args);
	return (p.ret);
}
