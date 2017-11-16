#include "ft_printf.h"

static int	is_type(t_print *p, char c)
{
	if ((c == 'c' || c == 'C' || c == 's' || c == 'S' ||
		c == 'o' || c == 'O' || c == 'd' || c == 'u' ||
		c == 'x' || c == 'X' || c == '%' || c == 'p') &&
		(p->f->type = c))
		return (1);
	return (0);
}

static int	is_flag(char c)
{
	if (c == '#' || c == '0' || c == '+' ||
		c == '-' || c == ' ')
		return (1);
	return (0);
}

static void	get_specs(t_print *p)
{
	while (p->fmt[p->i] && !(is_type(p, p->fmt[p->i])))
	{
		if (is_flag(p->fmt[p->i]))
			get_flags(p);
		else if (p->fmt[p->i] == '.')
			get_precision(p);
		else if (ft_isdigit(p->fmt[p->i]))
			get_width(p);
		else if (ft_isalpha(p->fmt[p->i]))
			get_length(p);
	}
}

void		arg_handle(t_print *p)
{
	get_specs(p);
	if (p->f->type == 'c' || p->f->type == 'C')
		charify(p);
	else if (p->f->type == 's' || p->f->type == 'S')
		stringify(p);
	else if (p->f->type == 'o' || p->f->type == 'O')
		octalfy(p);
	else if (p->f->type == 'd')
		decimalfy(p);
	else if (p->f->type == 'u')
		undecimalfy(p);
	else if (p->f->type == 'x' || p->f->type == 'X')
		hexify(p);
	else if (p->f->type == '%')
		percentify(p);
	else if (p->f->type == 'p')
		pointerfy(p);
}
