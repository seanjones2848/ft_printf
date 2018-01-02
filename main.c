#include <stdio.h>
#include "src/ft_printf.h"
#include <limits.h>

int		main(void)
{
	wchar_t wz [3] = L"@@";       // Zero-terminated
	ft_printf("%ls", wz);   // Outputs 6 bytes
	int			r00 = 0;
	ft_printf("Lalalala, %d%% des gens qui parlent à Ly adorent s%s. Ou Presque. %p", 100, "Ly", &r00);

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
	ft_printf("%%-*.3s LYDI == |%-*.3s|\n", 5, "LYDI");
	ft_printf("%% *.5i 42 == |% *.5i|\n", 4, 42);
	ft_printf("%%*i 42 == |%*i|\n", 5, 42);
	ft_printf("%%*i 42 == |%*i|\n", 3, 42);
	ft_printf("%%*i 42 == |%*i|\n", 2, 42);
	ft_printf("foop%adoop", (double)42);
	ft_printf("Kashim a %a histoires à raconter", (double)1001);
	ft_printf("Il fait au moins %a\n", (double)-8000);
	ft_printf("%a", (double)-0);
	ft_printf("%a", (double)0);
	ft_printf("%a", (double)INT_MAX);
	ft_printf("%a", (double)INT_MIN);
	ft_printf("%a", (double)INT_MIN - 1);
	ft_printf("%a", (double)INT_MAX + 1);
	ft_printf("%%a 0000042 == |%a|\n", (double)0000042);
	ft_printf("%%a \t == |%a|\n", (double)'\t');
	ft_printf("%%a Lydie == |%a|\n", (double)'L'+'y'+'d'+'i'+'e');
	ft_printf("%%a 42.42 == |%a|\n", 42.42);
	ft_printf("%A", (double)42);
	ft_printf("Kashim a %A histoires à raconter", (double)1001);
	ft_printf("Il fait au moins %A\n", (double)-8000);
	ft_printf("%A", (double)-0);
	ft_printf("%A", (double)0);
	ft_printf("%A", (double)INT_MAX);
	ft_printf("%A", (double)INT_MIN);
	ft_printf("%A", (double)INT_MIN - 1);
	ft_printf("%A", (double)INT_MAX + 1);
	ft_printf("%%A 0000042 == |%A|\n", (double)0000042);
	ft_printf("%%A \t == |%A|\n", (double)'\t');
	ft_printf("%%A Lydie == |%A|\n", (double)'L'+'y'+'d'+'i'+'e');
	ft_printf("%%A 42.42 == |%A|\n", 42.42);
	ft_printf("%%A 42.42 == |%.2A|\n", 42.42);
*/
	return (0);
}
