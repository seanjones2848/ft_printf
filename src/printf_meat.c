/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_meat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:01:39 by sjones            #+#    #+#             */
/*   Updated: 2017/11/27 13:03:25 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_fmt(t_print *p, int j)
{
	p->ret += write(p->fd, p->fmt + j, p->i - j);
}

void		printf_meat(t_print *p)
{
	int j;

	j = 0;
	while (p->fmt[p->i])
	{
		if (p->fmt[p->i] == '%')
		{
			print_fmt(p, j);
			reset(p);
			arg_handle(p);
			j = p->i + 1;
		}
		p->i++;
	}
	print_fmt(p, j);
}
