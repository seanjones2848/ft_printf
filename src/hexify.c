/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:01:13 by sjones            #+#    #+#             */
/*   Updated: 2017/11/27 13:01:15 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	make_upper(t_print *p)
{
	int i;

	i = -1;
	while (p->num[++i])
		if (ft_isalpha(p->num[i]))
			p->num[i] -= 32;
}

static void	format(t_print *p)
{
	p->num = ft_itoa_base(p->arg.u, 16);
	if (p->type == 'X')
		make_upper(p);
	p->len = ft_strlen(p->num);
	if (p->prec > p->len)
		p->zeroes = p->prec - p->len;
	if (p->width > p->len + p->zeroes)
		p->spaces = p->width - (p->len + p->zeroes);
}

void		hexify(t_print *p)
{
	unconvert(p);
	format(p);
	if (p->minus)
	{
		if (p->hash)
			p->ret += (p->type == 'x') ? (write(p->fd, "0x", 2))
				: (write(p->fd, "0X", 2));
		print_char(p, '0', p->zeroes);
		print_num(p);
		if (p->spaces > 0)
			print_char(p, ' ', p->spaces);
	}
	else
	{
		(p->zeroes > 0) ? (print_char(p, '0', p->spaces))
			: (print_char(p, ' ', p->spaces));
		if (p->hash)
			p->ret += (p->type == 'x') ? (write(p->fd, "0x", 2))
				: (write(p->fd, "0X", 2));
		print_char(p, '0', p->zeroes);
		print_num(p);
	}
}
