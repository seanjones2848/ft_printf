#include "ft_printf.h"

static void		init_flags(t_flags *f)
{
	f->hash = false;
	f->zero = false;
	f->plus = false;
	f->minus = false;
	f->space = false;
	f->width = 0;
	f->prec = -1;
	f->type = '\0';
	f->length = NULL;
}

void			init_print(t_print *p, int fd, char *fmt)
{
	t_flags	f;

	init_flags(&f);
	p->f = &f;
	p->fd = fd;
	p->fmt = fmt;
	p->len = 0;
	p->pad = 0;
	p->ret = 0;
	p->i = 0;
}
