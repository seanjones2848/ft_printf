#include "ft_printf.h"

void	unconvert(t_print *p)
{
	if (!(p->l_mod))
		p->arg.u = va_arg(p->args, unsigned int);
	else if (!(ft_strcmp(p->l_mod, "hh")))
		p->arg.u = (unsigned char)va_arg(p->args, unsigned int);
	else if (!(ft_strcmp(p->l_mod, "h")))
		p->arg.u = (unsigned short)va_arg(p->args, unsigned int);
	else if (!(ft_strcmp(p->l_mod, "ll")))
		p->arg.u = va_arg(p->args, unsigned long long int);
	else if (!(ft_strcmp(p->l_mod, "l")))
		p->arg.u = va_arg(p->args, unsigned long int);
	else if (!(ft_strcmp(p->l_mod, "j")))
		p->arg.u = va_arg(p->args, intmax_t);
	else if (!(ft_strcmp(p->l_mod, "z")))
		p->arg.u = va_arg(p->args, size_t);
}

void	convert(t_print *p)
{
	if (!(p->l_mod))
		p->arg.i = va_arg(p->args, int);
	else if (!(ft_strcmp(p->l_mod, "hh")))
		p->arg.i = (char)va_arg(p->args, int);
	else if (!(ft_strcmp(p->l_mod, "h")))
		p->arg.i = (short int)va_arg(p->args, int);
	else if (!(ft_strcmp(p->l_mod, "ll")))
		p->arg.i = va_arg(p->args, long long int);
	else if (!(ft_strcmp(p->l_mod, "l")))
		p->arg.i = va_arg(p->args, long int);
	else if (!(ft_strcmp(p->l_mod, "j")))
		p->arg.i = va_arg(p->args, intmax_t);
	else if (!(ft_strcmp(p->l_mod, "z")))
		p->arg.i = va_arg(p->args, size_t);
}
