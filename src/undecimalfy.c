#include "ft_printf.h"

static void	format(t_print *p)
{
	if (IS_NEG(p->arg.i) && (p->sign = '-'))
		p->arg.i *= -1;
	else if (p->f->plus)
		p->sign = '+';
	p->num = ft_itoa_base(p->arg.u, 10);
	p->len = ft_strlen(p->num);
	if (p->f->prec > p->len)
		p->zeroes = p->f->prec - p->len;
	if (p->f->width > p->len + p->zeroes)
		p->spaces = p->f->width - (p->len + p->zeroes);
}

void		undecimalfy(t_print *p)
{
	if (p->f->type == 'U')
		ft_strcpy(p->f->length, "l");
	unconvert(p);
	format(p);
	if (p->f->minus)
	{
		if (p->sign && (p->ret++))
			ft_putchar_fd(p->sign, p->fd);
		print_char(p, '0', p->zeroes);
		print_num(p);
		print_char(p, ' ', p->spaces);
	}
	else
	{
		if (p->sign && !p->f->zero && (p->ret++))
			ft_putchar_fd(p->sign, p->fd);
		(p->f->zero) ? print_char(p, '0', p->spaces)
			: print_char(p, ' ', p->spaces);
		print_char(p, '0', p->zeroes);
		print_num(p);
	}
}
