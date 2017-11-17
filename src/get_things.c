#include "ft_printf.h"

void	get_flags(t_print *p)
{
	while (IS_FLAG(p->fmt[p->i]))
	{
		if (p->fmt[p->i] == '#')
			p->f->hash = true;
		else if (p->fmt[p->i] == '0')
			p->f->zero = true;
		else if (p->fmt[p->i] == '+')
			p->f->plus = true;
		else if (p->fmt[p->i] == '-')
			p->f->minus = true;
		else if (p->fmt[p->i] == ' ')
			p->f->space = true;
		p->i++;
	}
}

void	get_prec(t_print *p)
{
	if (ft_isdigit(p->fmt[p->i]))
	{
		p->f->prec = ft_atoi(p->fmt + p->i);
		while (ft_isdigit(p->fmt[p->i]))
			p->i++;
	}
	else
		p->f->prec = 0;
}

void	get_width(t_print *p)
{
	p->f->width = ft_atoi(p->fmt + p->i);
	while (ft_isdigit(p->fmt[p->i]))
		p->i++;
}

void	get_length(t_print *p)
{
	if (p->fmt[p->i] == 'h' && p->fmt[p->i + 1] == 'h' && (p->i += 2))
		ft_strcpy(p->f->length, "hh");
	else if (p->fmt[p->i] == 'h' && (p->i++))
		ft_strcpy(p->f->length, "h");
	else if (p->fmt[p->i] == 'l' && p->fmt[p->i + 1] == 'l' && (p->i += 2))
		ft_strcpy(p->f->length, "ll");
	else if (p->fmt[p->i] == 'l' && (p->i++))
		ft_strcpy(p->f->length, "l");
	else if (p->fmt[p->i] == 'j' && (p->i++))
		ft_strcpy(p->f->length, "j");
	else if (p->fmt[p->i] == 'z' && (p->i++))
		ft_strcpy(p->f->length, "z");
}
