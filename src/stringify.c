#include "ft_printf.h"

static void	print_string(t_print *p)
{
	p->spaces = (p->f->prec != -1 && p->f->prec < p->len)
	? (p->f->prec) : (p->len);
	p->ret = write(p->fd, p->arg.s, p->spaces);
}

static void	print_spaces(t_print *p)
{
	p->spaces = (p->f->prec >= 0 && p->f->prec < p->len)
	? (p->f->width - p->f->prec) : (p->f->width - p->len);
	while (p->spaces > 0)
	{
		p->ret += write(p->fd, "           ", (p->spaces >= 10) ? 10 : p->spaces);
		p->spaces -= (p->spaces >= 10) ? 10 : p->spaces;
	}
}

void		stringify(t_print *p)
{
	p->arg.s = va_arg(p->args, char*);
	p->len = ft_strlen(p->arg.s);
	printf("str {%s}\n", p->arg.s);
	if (p->f->minus)
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