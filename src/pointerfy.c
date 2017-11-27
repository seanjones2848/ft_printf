/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointerfy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:01:29 by sjones            #+#    #+#             */
/*   Updated: 2017/11/27 13:01:30 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		pointerfy(t_print *p)
{
	p->arg.u = va_arg(p->args, unsigned long int);
	p->num = ft_itoa_base(p->arg.u, 16);
	p->ret += write(p->fd, "0x", 2);
	p->ret += write(p->fd, p->num, ft_strlen(p->num));
}
