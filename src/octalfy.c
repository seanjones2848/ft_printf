#include "ft_printf.h"


static void	format(t_print *p)
{
	p->num = ft_itoa_base(p->arg.u, 8);
	p->len = ft_strlen(p->num);
	if (p->f->hash && p->num[0] != '0')
		p->zeroes++;
	if (p->f->prec > p->len + p->zeroes)
		p->zeroes = p->f->prec - p->len;
	if (p->f->minus)
		p->spaces = p->f->width - (p->zeroes + p->len);
	else
		(p->f->zero) ? (p->zeroes += p->f->width - (p->zeroes + p->len))
			: (p->spaces = p->f->width - (p->zeroes + p->len));
}

void		octalfy(t_print *p)
{
	if (p->f->type == 'O')
		ft_strcpy(p->f->length, "l");
	unconvert(p);
	format(p);
	if (p->f->minus)
	{
		print_char(p, '0', p->zeroes);
		print_num(p);
		print_char(p, ' ', p->spaces);
	}
	else
	{
		print_char(p, ' ', p->spaces);
		print_char(p, '0', p->zeroes);
		print_num(p);
	}
}
