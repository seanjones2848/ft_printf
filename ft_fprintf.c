#include "ft_printf.h"

int			ft_fprintf(int fd, const char *fmt, ...)
{
	t_print		p;

	init_print(&p, fd, (char*)fmt);
	va_start(p.args, fmt);
	printf_meat(&p);
	va_end(p.args);
	return (p.ret);
}
