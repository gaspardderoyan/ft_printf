#include "helpers.h"
#include "types.h"

void	p_char(va_list *ptr, int *ccount)
{
	char	c;

	c = (char)va_arg(*ptr, int);
	write(1, &c, 1);
	(*ccount)++;
}

void	p_int(va_list *ptr, int *ccount)
{
	char	*str;
	int		len;

	str = ft_itoa(va_arg(*ptr, int));
	len = ft_strlen(str);
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

void	p_str(va_list *ptr, int *ccount)
{
	char	*str;
	int		len;

	str = va_arg(*ptr, char *);
	len = ft_strlen(str);
	*ccount += len;
	write(1, str, len);
}
