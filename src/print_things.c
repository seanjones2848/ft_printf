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

void	print_all(t_print *p)
{
	printf("\n--All of the print_struct\nfmt {%s}\nnum {%s}\nsign {%c}\nspaces {%d}\nzeroes {%d}\nlen {%d}\nret {%d}\ni {%d}\n--All flags\nhash {%d}\nzero {%d}\nplus {%d}\nminus {%d}\nspace {%d}\nwidth {%d}\nprec {%d}\ntype {%c}\nlength {%s}\n\n", p->fmt, p->num, p->sign, p->spaces, p->zeroes, p->len, p->ret, p->i, (int)p->hash, (int)p->zero, (int)p->plus, (int)p->minus, (int)p->space, p->width, p->prec, p->type, p->l_mod);
}
