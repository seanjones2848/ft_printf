#include "ft_printf.h"

static void	print_char(t_print *p)
{
	ft_putchar_fd(p->fd, p->arg.c);
	p->ret++;
}

static void	print_spaces(t_print *p)
{
	p->pad = p->f->width - p->len;
	while (p->pad > 0)
	{
		p->ret = write(1, "          ", (p->pad >= 10) ? (10) : (p->pad));
		p->pad -= (p->pad >= 10) ? (10) : (p->pad);
	}
}

void		charify(t_print *p)
{
	p->arg.c = (char)va_arg(p->args, int);
	p->len = 1;
	if (p->f->minus)
	{
		print_char(p);
		print_spaces(p);
	}
	else
	{
		print_spaces(p);
		print_char(p);
	}
}
