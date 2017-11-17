#include <stdio.h>
#include "src/ft_printf.h"

int		main(void)
{
	printf("%d, %d\n", printf("derp\n"), ft_printf("derp\n"));
	return (0);
}
