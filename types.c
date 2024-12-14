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
	uintptr_t		adr;	
	char		*str;
	int			len;

	adr = (uintptr_t)va_arg(*ptr, uintptr_t);
	if (!adr)
	{
		write(1, "(nil)", 5);
		*ccount += 5;
	}
	else
	{
		str = ft_itohex(adr);
		len = strlen_safe(str);
		*ccount += len + 2;
		write(1, "0x", 2);
		write(1, str, len);
		free(str);
	}
}

void	p_hex_low(va_list *ptr, int *ccount)
{
	uintptr_t		adr;	
	char		*str;
	int			len;

	adr = (unsigned int)va_arg(*ptr, unsigned int);
	str = ft_itohex(adr);
	len = strlen_safe(str);
	*ccount += len;
	write(1, str, len);
	free(str);
}

void	p_hex_upp(va_list *ptr, int *ccount)
{
	uintptr_t		adr;	
	char		*str;
	int			len;

	adr = (unsigned int)va_arg(*ptr, unsigned int);
	str = ft_itohex_upper(adr);
	len = strlen_safe(str);
	*ccount += len;
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

void	p_ulong(va_list *ptr, int *ccount)
{
	char	*str;
	int		len;

	str = ft_utoa(va_arg(*ptr, unsigned long));
	len = strlen_safe(str);
	if (str)
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
