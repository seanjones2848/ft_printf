
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h> //in place of my libft

typedef struct	s_flags
{
	int			hash:1;
	int			zero:1;
	int			plus:1;
	int			minus:1;
	int			space:1;
	int			width;
	int			precison;
}				t_flags;

typedef struct	s_print
{
	t_flags		*f;
	va_list		*args;
	char		*fmt;
	int			ret;
}				t_print;

t_print			*init_print(char *fmt, va_list *args);
int				ft_printf(char *fmt, ...);
#endif
