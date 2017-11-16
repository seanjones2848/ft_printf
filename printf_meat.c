#include "ft_printf.h"
#include "libft/libft.h"

static void	print_fmt(t_print *p, int j)
{
	write(p->fd, p->fmt + j, p->i - j);
	p->ret += p->i - j;
}

void		printf_meat(t_print *p)
{
	int j;

	j = 0;
	while (p->fmt[p->i])
	{
		if (p->fmt[p->i] == '%')
		{
			print_fmt(p, j);
			arg_handle(p);
			j = p->i + 1;
		}
		p->i++;
	}
	printf("i:{%d}, j{%d}\n", p->i, j);
	print_fmt(p, j);
}


