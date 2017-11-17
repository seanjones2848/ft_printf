
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>

# include <stdio.h> //for debugging

# define IS_TYPE(c) (c == 's' || c == 'S' || c == 'p'\
	|| c == 'd' || c == 'D' || c == 'i' || c == 'o'\
	|| c == 'O' || c == 'u' || c == 'U' || c == 'x'\
	|| c == 'X' || c == 'c' || c == 'C' || c == '%')\
	? (1) : (0)
# define IS_FLAG(c) (c == '#' || c == '0' || c == '+'\
	|| c == '-' || c == ' ') ? (1) : (0)

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
	int			prec;
	char		type;
	char		*length;
}				t_flags;

typedef struct	s_print
{
	t_flags		*f;
	va_list		args;
	types		arg;
	char		*fmt;
	char		*num;
	char		sign;
	int			spaces;
	int			zeroes;
	int			len;
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
void			get_prec(t_print *p);
void			get_width(t_print *p);
void			get_length(t_print *p);
void			convert(t_print *p);
void			unconvert(t_print *p);
void			reset(t_print *p);
void			print_char(t_print *p, char c, int t);
void			print_num(t_print *p);

/*
** formaters
*/

void			charify(t_print *p);
void			stringify(t_print *p);
void			octalfy(t_print *p);
void			decimalfy(t_print *p);
void			undecimalfy(t_print *p);
void			hexify(t_print *p);
void			pointerfy(t_print *p);

#endif
