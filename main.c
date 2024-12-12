#include <stdarg.h>
#include <unistd.h>

/*
void	choose_fun(char type, void **ptr)
{
	if (type == 'c')
}
*/

int	ft_printf(const char *str, ...)
{
	va_list ptr;
	int	n_of_chars;

	n_of_chars = 0;
	va_start(ptr, str);
	while (*str)	
	{
		if (*str != '%')
		{
			write(1, str, 1);
			n_of_chars++;
		}
		else if (*(str + 1) == 'c')
		{
			char c = (char)va_arg(ptr, int);	
			write(1, &c, 1);
			str++;
			n_of_chars++;
		}
		str++;
	}
	va_end(ptr);
	return(n_of_chars);
}

#include <stdio.h>
int	main(void)
{
	int	count;
	
	count = ft_printf("This should print an X --> %c.\nv --> %c\n", 'X', 'v'); 
	printf("Count of chars: %d\n", count);
	return (0);
}
