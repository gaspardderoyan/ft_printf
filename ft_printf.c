#include "ft_printf.h"

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
	else if (type == '%')
	{
		write(1, "%", 1);
		(*ccount)++;
	}
	else
	{
		write(1, *str, 1);
		write(1, *str + 1, 1);
		*ccount += 2;
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
