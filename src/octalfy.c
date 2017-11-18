#include "ft_printf.h"


static void	format(t_print *p)
{
	p->num = ft_itoa_base(p->arg.u, 8);
	p->len = ft_strlen(p->num);
	if (p->hash && p->num[0] != '0')
		p->zeroes++;
	if (p->prec > p->len + p->zeroes)
		p->zeroes = p->prec - p->len;
	if (p->minus)
		p->spaces = p->width - (p->zeroes + p->len);
	else
		(p->zero) ? (p->zeroes += p->width - (p->zeroes + p->len))
			: (p->spaces = p->width - (p->zeroes + p->len));
}

void		octalfy(t_print *p)
{
	if (p->type == 'O')
		ft_strcpy(p->l_mod, "l");
	unconvert(p);
	format(p);
	if (p->minus)
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
