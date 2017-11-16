#include "ft_printf.h"

static void		init_flags(t_flags *f)
{
	f->hash = false;
	f->zero = false;
	f->plus = false;
	f->minus = false;
	f->space = false;
	f->width = 0;
	f->precision = 0;
	f->type = 0;
}

void			init_print(t_print *p, int fd, char *fmt)
{
	t_flags	f;

	init_flags(&f);
	p->f = &f;
	p->fd = fd;
	p->fmt = fmt;
	p->str = fmt;
	p->ret = 0;
	p->i = 0;
}
