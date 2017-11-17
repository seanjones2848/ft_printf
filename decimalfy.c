#include "ft_printf.h"

static void	format(t_print *p)
{
	if (IS_NEG(p->arg.i) && (p->sign = '-') && (p->len++))
		p->arg.i *= -1;
	else if (p->f->plus && (p->sign == '+'))
		p->len++;
	p->num = ft_itoa_base(p->arg.i, 10);
	p->len += ft_strlen(p->num);
	if (p->f->prec > p->len)
		p->zeroes = p->f->prec - p->len;
	if (p->f->width > p->len + p->zeroes)
		p->spaces = p->f->width - (p->len + p->zeroes);
}

static void print_char(t_print *p, char c, int t)
{
	p->ret += t;
	while (t > 0)
	{
		ft_putchar_fd(c, p->fd);
		t--;
	}
}

static void	print_num(t_print *p)
{
	p->ret += write(p->fd, p->num, (p->len - (p->sign) ? (1) : (0)));
}

void		decimalfy(t_print *p)
{
	if (p->f->type == 'D')
		strcpy(p->f->length, "l");
	convert(p);
	format(p);
	if (p->f->minus)
	{
		if (p->sign && p->ret++)
			ft_putchar_fd(p->sign, p->fd);
		print_char(p, '0', p->zeroes);
		print_num(p);
		print_char(p, ' ', p->spaces);
	}
	else
	{
		(p->f->zero) ? print_char(p, '0', p->spaces)
			: print_char(p, ' ', p->spaces);
		if (p->sign && !p->f->zero && (p->ret++))
			ft_putchar_fd(p->sign, p->fd);
		print_char(p, '0', p->zeroes);
		print_num(p);
	}
}
