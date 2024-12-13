#include "helpers.h"
#include "types.h"

void	p_char(va_list *ptr, int *ccount)
{
	char	c;

	c = (char)va_arg(*ptr, int);
	write(1, &c, 1);
	(*ccount)++;
}

void	p_str(va_list *ptr, int *ccount)
{
	char	*str;
	int		len;

	str = va_arg(*ptr, char *);
	len = strlen_safe(str);
	*ccount += len;
	if (str)
		write(1, str, len);
	else
	{
		write(1, "(null)", 6);
		*ccount += 6;
	}
}

void	p_ptr(va_list *ptr, int *ccount)
{
	long		adr;	
	char		*str;
	int			len;

	adr = (long)va_arg(*ptr, long);
	str = ft_itohex(adr);
	len = strlen_safe(str);
	*ccount += len + 2;
	write(1, "0x", 2);
	write(1, str, len);
	free(str);
}

void	p_int(va_list *ptr, int *ccount)
{
	char	*str;
	int		len;

	str = ft_itoa(va_arg(*ptr, int));
	len = strlen_safe(str);
	write(1, str, len);
	free(str);
	*ccount += len;
}

void	p_percent(int *ccount)
{
		write(1, "%", 1);
		(*ccount)++;
}

void	p_else(const char *str, int *ccount)
{
	write(1, str, 1);
	write(1, str + 1, 1);
	*ccount += 2;
}
