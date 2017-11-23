#include <stdio.h>
#include "src/ft_printf.h"

int		main(void)
{
	long int i = -1;

//	for (int j = 0; j < 10; j++) {
	printf("%d, %d\n", printf("p%-+5.0ld\n", i), ft_printf("f%-+5.0ld\n", i));
	printf("%d, %d\n", printf("p%0lu\n", i), ft_printf("f%0lu\n", i));
	printf("%d, %d\n", printf("p%lo\n", i), ft_printf("f%lo\n", i));
	printf("%d, %d\n", printf("p%lx\n", i), ft_printf("f%lx\n", i));
	i++; //}
	char *s1 = "derp";
	printf("%d, %d\n", printf("pderp\n"), ft_printf("fderp\n"));
	printf("%d, %d\n", printf("p\n"), ft_printf("f\n"));
	printf("%d, %d\n", printf("pherp %s\n", s1), ft_printf("fherp %s\n", s1));
	printf("%d, %d\n", printf("p%21s\n", s1), ft_printf("f%21s\n", s1));
	printf("%d, %d\n", printf("p%-21s\n", s1), ft_printf("f%-21s\n", s1));
	return (0);
}
