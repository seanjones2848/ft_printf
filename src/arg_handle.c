/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:00:19 by sjones            #+#    #+#             */
/*   Updated: 2018/01/01 17:24:59 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			is_type(char c)
{
	return (c == 's' || c == 'S' || c == 'p'\
	|| c == 'd' || c == 'D' || c == 'i' || c == 'o'\
	|| c == 'O' || c == 'u' || c == 'U' || c == 'x'\
	|| c == 'X' || c == 'c' || c == 'C' || c == '%')\
	? (1) : (0);
}

int			is_flag(char c)
{
	return (c == '#' || c == '0' || c == '+'\
	|| c == '-' || c == ' ') ? (1) : (0);
}

static int	set_type(t_print *p, char c)
{
	if ((is_type(c)) && (p->type = c))
		return (1);
	return (0);
}

static void	get_specs(t_print *p)
{
	int star;

	while (p->fmt[p->i] && !(set_type(p, p->fmt[p->i])))
	{
		if (is_flag(p->fmt[p->i]))
			get_flags(p);
		else if (p->fmt[p->i] == '.' && p->i++)
			get_prec(p);
		else if (ft_isdigit(p->fmt[p->i]))
			get_width(p);
		else if (ft_isalpha(p->fmt[p->i]))
			get_length(p);
		else if (p->fmt[p->i] == '*' && p->i++)
			star = va_arg(p->args, int);
	}
}

void		arg_handle(t_print *p)
{
	p->i++;
	get_specs(p);
	if (p->type == 's' || p->type == 'S')
		stringify(p);
	else if (p->type == 'p')
		pointerfy(p);
	else if (p->type == 'd' || p->type == 'D' || p->type == 'i')
		decimalfy(p);
	else if (p->type == 'o' || p->type == 'O')
		octalfy(p);
	else if (p->type == 'u' || p->type == 'U')
		undecimalfy(p);
	else if (p->type == 'x' || p->type == 'X')
		hexify(p);
	else if (p->type == 'c' || p->type == 'C')
		charify(p);
	else if (p->type == '%')
		p->ret = write(p->fd, "%", 1);
}
