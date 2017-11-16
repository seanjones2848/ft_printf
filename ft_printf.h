
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>

# include <stdio.h> //for debugging

typedef union
{
	char		c;
	char		*s;
	intmax_t	i;
	uintmax_t	u;
	void		*v;
}				types;

typedef struct	s_flags
{
	bool		hash;
	bool		zero;
	bool		plus;
	bool		minus;
	bool		space;
	int			width;
	int			precision;
	char		type;
}				t_flags;

typedef struct	s_print
{
	t_flags		*f;
	va_list		args;
	char		*fmt;
	char		*str;
	int			ret;
	int			fd;
	int			i;
}				t_print;

/*
** printf types
*/

int				ft_printf(const char *fmt, ...);
int				ft_fprintf(int fd, const char *fmt, ...);

/*
** printf meat
*/

void			init_print(t_print *p, int fd, char *fmt);
void			printf_meat(t_print *p);
void			arg_handle(t_print *p);
void			get_flags(t_print *p);
void			get_precision(t_print *p);
void			get_width(t_print *p);
void			get_length(t_print *p);


/*
** formaters
*/

void			charify(t_print *p);
void			stringify(t_print *p);
void			octalfy(t_print *p);
void			decimalfy(t_print *p);
void			undecimalfy(t_print *p);
void			hexify(t_print *p);
void			percentify(t_print *p);
void			pointerfy(t_print *p);

#endif
