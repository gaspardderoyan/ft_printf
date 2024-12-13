#include "ft_printf.h"
#include "types.h"

void	choose_fun(va_list *ptr, const char **str, int *ccount)
{
	char type;

	type = *(*str + 1);
	if (type == 'c')
		p_char(ptr, ccount);
	else if (type == 's')
		p_str(ptr, ccount);
	else if (type == 'i')
		p_int(ptr, ccount);
	else if (type == '%')
		p_percent(ccount);
	else
		p_else(*str, ccount);
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
