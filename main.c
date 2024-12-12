#include <stdarg.h>
#include <unistd.h>

size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);

void	choose_fun(va_list *ptr, const char **str, int *ccount)
{
	char type;

	type = *(*str + 1);
	if (type == 'c')
	{
		char c = (char)va_arg(*ptr, int);
		write(1, &c, 1);
		(*ccount)++;
	}
	else if (type == 'i')
	{
		char *str = ft_itoa(va_arg(*ptr, int));
		int len = ft_strlen(str);
		write(1, str, len);
		*ccount += len;
	}
	(*str)++;
}

int	ft_printf(const char *str, ...)
{
	va_list ptr;
	int	ccount;

	ccount = 0;
	va_start(ptr, str);
	while (*str)	
	{
		if (*str != '%')
		{
			write(1, str, 1);
			ccount++;
		}
		else if (*(str + 1))
			choose_fun(&ptr, &str, &ccount);
		str++;
	}
	va_end(ptr);
	return(ccount);
}

#include <stdio.h>
int	main(void)
{
	int	count;
	
	count = ft_printf("This should print an X --> %c.\nv --> %c\n", 'X', 'v'); 
	count += ft_printf("This should print 1337 --> %i.\n", 1337); 
	printf("Count of chars: %d\n", count);
	return (0);
}
