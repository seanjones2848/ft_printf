#include "ft_printf.h"

static void	print_string(t_print *p)
{
	p->pad = (p->f->prec != -1 && p->f->prec < p->len)
	? (p->f->prec) : (p->len);
	p->ret = write(p->fd, p->arg.s, p->pad);
}

static void	print_spaces(t_print *p)
{
	p->pad = (p->f->prec >= 0 && p->f->prec < p->len)
	? (p->f->width - p->f->prec) : (p->f->width - p->len);
	while (p->pad > 0)
	{
		p->ret += write(p->fd, "           ", (p->pad >= 10) ? 10 : p->pad);
		p->pad -= (p->pad >= 10) ? 10 : p->pad;
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
