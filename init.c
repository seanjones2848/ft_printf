#include "ft_printf.h"

static t_flags	*init_flags(void)
{
	t_flags		*f;

	if (!(f = (t_flags*)malloc(sizeof(t_flags))))
	{
		write(2, "malloc failed for t_flags\n", 26);
		return (NULL);
	}
	bzero(f, sizeof(t_flags));
	return (f);
}

t_print			*init_print(char *fmt, va_list *args)
{
	t_print		*p;

	if (!(p = (t_print*)malloc(sizeof(t_print))))
	{
		write(2, "malloc failed for t_print\n", 26);
		return (NULL);
	}
	bzero(p, sizeof(t_print)); //need to sub out for libft function
	if ((p->f = init_flags()) == NULL)
		return (NULL);
	p->fmt = fmt;
	p->args = args;
	return (p);
}
