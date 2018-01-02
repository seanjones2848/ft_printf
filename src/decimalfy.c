/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimalfy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:00:42 by sjones            #+#    #+#             */
/*   Updated: 2018/01/01 20:19:53 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	format(t_print *p)
{
	p->num = ft_itoa_base(p->arg.i, 10);
	p->len = ft_strlen(p->num);
	if (p->prec > p->len)
		p->zeroes = p->prec - p->len;
	if (p->width > p->len + p->zeroes)
		p->spaces = p->width - (p->len + p->zeroes);
	if (p->plus && !(IS_NEG(p->arg.i)))
		p->sign = '+';
	if (p->plus && p->zero)
		p->spaces--;
	if (p->space && !(IS_NEG(p->arg.i)) && p->spaces == 0)
		p->spaces++;
}

void		decimalfy(t_print *p)
{
	if (p->type == 'D')
		p->l_mod = "l";
	convert(p);
	format(p);
	if (p->minus)
	{
		if (p->sign && !p->zero && p->ret++)
			ft_putchar_fd(p->sign, p->fd);
		print_char(p, '0', p->zeroes);
		print_num(p);
		print_char(p, ' ', p->spaces);
	}
	else
	{
		if (p->sign && (p->ret++))
			ft_putchar_fd(p->sign, p->fd);
		print_char(p, ' ', p->spaces);
		print_char(p, '0', p->zeroes);
		print_num(p);
	}
}
