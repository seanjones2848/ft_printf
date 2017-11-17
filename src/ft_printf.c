#include "ft_printf.h"

int			ft_printf(const char *fmt, ...)
{
	t_print		p;

	init_print(&p, 1, (char*)fmt);
	va_start(p.args, fmt);
	printf_meat(&p);
	va_end(p.args);
	return (p.ret);
}
