#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	count;
	
	printf("\n--- TEST OUTPUT ---\n\n");
	count = ft_printf("X --> %c\nv --> %c\n", 'X', 'v'); 
	count += ft_printf("1337 --> %i\nz --> %c\n", 1337, 'z'); 
	count += ft_printf("% --> %%\nz --> %c\n", 'z'); 
	printf("Count of chars: %d\n", count);
	return (0);
}
