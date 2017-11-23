#include "ft_printf.h"

static int	is_type(t_print *p, char c)
{
	if ((IS_TYPE(c)) && (p->type = c))
		return (1);
	return (0);
}

static void	get_specs(t_print *p)
{
	while (p->fmt[p->i] && !(is_type(p, p->fmt[p->i])))
	{
		if (IS_FLAG(p->fmt[p->i]))
			get_flags(p);
		else if (p->fmt[p->i] == '.' && p->i++)
			get_prec(p);
		else if (ft_isdigit(p->fmt[p->i]))
			get_width(p);
		else if (ft_isalpha(p->fmt[p->i]))
			get_length(p);
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
