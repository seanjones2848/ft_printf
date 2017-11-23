#include <stdio.h>
#include "src/ft_printf.h"

int		main(void)
{
	unsigned int i = -1;

//	for (int j = 0; j < 10; j++) {
	printf("%d, %d\n", printf("p%.0d\n", i), ft_printf("f%.0d\n", i));
	printf("%d, %d\n", printf("p%0u\n", i), ft_printf("f%0u\n", i));
	printf("%d, %d\n", printf("p%o\n", i), ft_printf("f%o\n", i));
	printf("%d, %d\n", printf("p%x\n", i), ft_printf("f%x\n", i));
	i++; //}
	char *s1 = "derp";
	printf("%d, %d\n", printf("pderp\n"), ft_printf("fderp\n"));
	printf("%d, %d\n", printf("p\n"), ft_printf("f\n"));
	printf("%d, %d\n", printf("pherp %s\n", s1), ft_printf("fherp %s\n", s1));
	printf("%d, %d\n", printf("p%21s\n", s1), ft_printf("f%21s\n", s1));
	printf("%d, %d\n", printf("p%-21s\n", s1), ft_printf("f%-21s\n", s1));
	return (0);
}
