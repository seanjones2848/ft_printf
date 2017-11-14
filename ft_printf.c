#include "ft_printf.h"

int		ft_printf(char *fmt, ...)
{
	t_print		*p;
	va_list		args;

	va_start(args, fmt);
	if ((p = init_print(fmt, &args)) == NULL)
		return (-1);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			write(1, &fmt, 1);
			p->ret += 1;
		}
		else
		{
			write(1, &fmt, 1);
			p->ret += 1;
		}
		fmt++;
	}
	va_end(args);
	return (p->ret);
}
