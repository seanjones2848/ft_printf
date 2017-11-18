#include "ft_printf.h"

static void	print_spaces(t_print *p)
{
	p->spaces = p->width - p->len;
	while (p->spaces > 0)
	{
		p->ret = write(1, "          ", (p->spaces >= 10) ? (10) : (p->spaces));
		p->spaces -= (p->spaces >= 10) ? (10) : (p->spaces);
	}
}

void		charify(t_print *p)
{
	p->arg.c = (char)va_arg(p->args, int);
	p->len = 1;
	if (p->minus)
	{
		print_char(p, p->arg.c, 1);
		print_spaces(p);
	}
	else
	{
		print_spaces(p);
		print_char(p, p->arg.c, 1);
	}
}
