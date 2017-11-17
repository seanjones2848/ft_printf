#include "ft_printf.h"

void		pointerfy(t_print *p)
{
	p->arg.u = va_arg(p->args, unsigned long int);
	p->num = ft_itoa_base(p->arg.u, 16);
	p->ret += write(p->fd, "0x", 2);
	p->ret += write(p->fd, p->num, ft_strlen(p->num));
}
