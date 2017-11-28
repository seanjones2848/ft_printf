/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:01:44 by sjones            #+#    #+#             */
/*   Updated: 2017/11/28 12:48:57 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_string(t_print *p)
{
	p->spaces = (p->prec != -1 && p->prec < p->len)
	? (p->prec) : (p->len);
	p->ret += write(p->fd, p->arg.s, p->spaces);
}

static void	print_spaces(t_print *p)
{
	p->spaces = (p->prec >= 0 && p->prec < p->len)
	? (p->width - p->prec) : (p->width - p->len);
	while (p->spaces > 0)
	{
		p->ret += write(p->fd, "           ",
			(p->spaces >= 10) ? 10 : p->spaces);
		p->spaces -= (p->spaces >= 10) ? 10 : p->spaces;
	}
}

void		stringify(t_print *p)
{
	p->arg.s = va_arg(p->args, char*);
	if (!p->arg.s && write(p->fd, "(null)", 6))
		return;
	p->len = ft_strlen(p->arg.s);
	if (p->minus)
	{
		print_string(p);
		print_spaces(p);
	}
	else
	{
		print_spaces(p);
		print_string(p);
	}
}
