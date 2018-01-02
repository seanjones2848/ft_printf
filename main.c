#include <stdio.h>
#include "src/ft_printf.h"

int		main(void)
{
//	long int i = 232146792314764219;

//	for (int j = 0; j < 10; j++) {
/*	printf("%d, %d\n", printf("p%-+5.0ld\n", i), ft_printf("f%-+5.0D\n", i));
	printf("%d, %d\n", printf("p%0lu\n", i), ft_printf("f%0U\n", i));
	printf("%d, %d\n", printf("p%lo\n", i), ft_printf("f%O\n", i));
	printf("%d, %d\n", printf("p%lx\n", i), ft_printf("f%lx\n", i));
	i++; //}
	char *s1 = "derp";
	printf("%d, %d\n", printf("pderp\n"), ft_printf("fderp\n"));
	printf("%d, %d\n", printf("p\n"), ft_printf("f\n"));
	printf("%d, %d\n", printf("pherp %.0s\n", s1), ft_printf("fherp %.0s\n", s1));
	printf("%d, %d\n", printf("p%21.3s\n", s1), ft_printf("f%21.3s\n", s1));
	printf("%d, %d\n", printf("p%-21s\n", s1), ft_printf("f%-21s\n", s1));
//	printf("%d, %d\n", printf("% h"), ft_printf("% h"));
*/	ft_printf("%%-*.3s LYDI == |%-*.3s|\n", 5, "LYDI");
	ft_printf("%% *.5i 42 == |% *.5i|\n", 4, 42);
	ft_printf("%%*i 42 == |%*i|\n", 5, 42);
	ft_printf("%%*i 42 == |%*i|\n", 3, 42);
	ft_printf("%%*i 42 == |%*i|\n", 2, 42);
	
	return (0);
}
