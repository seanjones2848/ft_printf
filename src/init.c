/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:01:20 by sjones            #+#    #+#             */
/*   Updated: 2017/11/27 13:01:21 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_print(t_print *p, int fd, char *fmt)
{
	p->hash = false;
	p->zero = false;
	p->plus = false;
	p->minus = false;
	p->space = false;
	p->width = 0;
	p->prec = -1;
	p->type = '\0';
	p->l_mod = NULL;
	p->fd = fd;
	p->fmt = fmt;
	p->num = NULL;
	p->sign = 0;
	p->spaces = 0;
	p->zeroes = 0;
	p->len = 0;
	p->ret = 0;
	p->i = 0;
}

void		reset(t_print *p)
{
	p->hash = false;
	p->zero = false;
	p->plus = false;
	p->minus = false;
	p->space = false;
	p->width = 0;
	p->prec = -1;
	p->type = '\0';
	p->l_mod = NULL;
	p->num = NULL;
	p->sign = 0;
	p->spaces = 0;
	p->zeroes = 0;
	p->len = 0;
}
