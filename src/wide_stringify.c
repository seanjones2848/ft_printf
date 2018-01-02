/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_stringify.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:01:44 by sjones            #+#    #+#             */
/*   Updated: 2018/01/01 18:46:06 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_wstrlen(wchar_t *w)
{
	size_t	i;

	i = 0;
	while (w[i] != L'\0')
		i++;
	return (i);
}

static void	print_string(t_print *p)
{
	p->spaces = (p->prec != -1 && p->prec < p->len)
	? (p->prec) : (p->len);
	p->ret += write(p->fd, p->arg.w, p->spaces);
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
	p->arg.w = va_arg(p->args, wchar_t*);
	if (!p->arg.w && (p->ret = write(p->fd, "(null)", 6)))
		return;
	p->len = ft_wstrlen(p->arg.w);
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
