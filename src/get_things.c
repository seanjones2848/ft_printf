#include "ft_printf.h"

void	get_flags(t_print *p)
{
	while (IS_FLAG(p->fmt[p->i]))
	{
		if (p->fmt[p->i] == '#')
			p->hash = true;
		else if (p->fmt[p->i] == '0')
			p->zero = true;
		else if (p->fmt[p->i] == '+')
			p->plus = true;
		else if (p->fmt[p->i] == '-')
			p->minus = true;
		else if (p->fmt[p->i] == ' ')
			p->space = true;
		p->i++;
	}
}

void	get_prec(t_print *p)
{
	if (ft_isdigit(p->fmt[p->i]))
	{
		p->prec = ft_atoi(p->fmt + p->i);
		while (ft_isdigit(p->fmt[p->i]))
			p->i++;
	}
	else
		p->prec = 0;
}

void	get_width(t_print *p)
{
	p->width = ft_atoi(p->fmt + p->i);
	while (ft_isdigit(p->fmt[p->i]))
		p->i++;
}

void	get_length(t_print *p)
{
	if (p->fmt[p->i] == 'h' && p->fmt[p->i + 1] == 'h' && (p->i += 2))
		ft_strcpy(p->l_mod, "hh");
	else if (p->fmt[p->i] == 'h' && (p->i++))
		ft_strcpy(p->l_mod, "h");
	else if (p->fmt[p->i] == 'l' && p->fmt[p->i + 1] == 'l' && (p->i += 2))
		ft_strcpy(p->l_mod, "ll");
	else if (p->fmt[p->i] == 'l' && (p->i++))
		ft_strcpy(p->l_mod, "l");
	else if (p->fmt[p->i] == 'j' && (p->i++))
		ft_strcpy(p->l_mod, "j");
	else if (p->fmt[p->i] == 'z' && (p->i++))
		ft_strcpy(p->l_mod, "z");
}
