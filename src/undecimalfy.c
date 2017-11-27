/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undecimalfy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:01:48 by sjones            #+#    #+#             */
/*   Updated: 2017/11/27 13:01:49 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	format(t_print *p)
{
	if (IS_NEG(p->arg.i) && (p->sign = '-'))
		p->arg.i *= -1;
	else if (p->plus)
		p->sign = '+';
	p->num = ft_itoa_base(p->arg.u, 10);
	p->len = ft_strlen(p->num);
	if (p->prec > p->len)
		p->zeroes = p->prec - p->len;
	if (p->width > p->len + p->zeroes)
		p->spaces = p->width - (p->len + p->zeroes);
}

void		undecimalfy(t_print *p)
{
	if (p->type == 'U')
		p->l_mod = "l";
	unconvert(p);
	format(p);
	if (p->minus)
	{
		if (p->sign && (p->ret++))
			ft_putchar_fd(p->sign, p->fd);
		print_char(p, '0', p->zeroes);
		print_num(p);
		print_char(p, ' ', p->spaces);
	}
	else
	{
		if (p->sign && !p->zero && (p->ret++))
			ft_putchar_fd(p->sign, p->fd);
		(p->zero) ? print_char(p, '0', p->spaces)
			: print_char(p, ' ', p->spaces);
		print_char(p, '0', p->zeroes);
		print_num(p);
	}
}
