#include "ft_printf.h"

void	print_char(t_print *p, char c, int t)
{
	p->ret += t;
	while (t > 0)
	{
		ft_putchar_fd(c, p->fd);
		t--;
	}
}

void	print_num(t_print *p)
{
	p->ret += write(p->fd, p->num, p->len);
}

