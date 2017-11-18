#include <stdio.h>
#include "src/ft_printf.h"

int		main(void)
{
	char *s1 = "derp";
	printf("%d, %d\n", printf("derp\n"), ft_printf("derp\n"));
	printf("%d, %d\n", printf("herp %s\n", s1), ft_printf("herp %s\n", s1));
	printf("%d, %d\n", printf("%8s\n", s1), ft_printf("%8s\n", s1));
	printf("%d, %d\n", printf("%-8s\n", s1), ft_printf("%-8s\n", s1));
	return (0);
}
