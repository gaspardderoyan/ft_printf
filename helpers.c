#include "helpers.h"

size_t	strlen_safe(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (*s++)
		i++;
	return (i);
}

static unsigned int	ft_abs(int n)
{
	unsigned int	num;

	if (n == INT_MIN)
		num = (unsigned int)INT_MAX + 1;
	else if (n < 0)
		num = -n;
	else
		num = n;
	return (num);
}

static int	ft_nbr_len(int n)
{
	int				len;
	unsigned int	num;

	len = 0;
	if (n <= 0)
		len = 1;
	num = ft_abs(n);
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static int	ft_hex_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int					len;
	char				*res;
	unsigned int		num;

	len = ft_nbr_len(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	num = ft_abs(n);
	if (n == 0)
	{
		res[0] = '0';
		return (res);
	}
	while (num != 0)
	{
		res[--len] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		res[--len] = '-';
	return (res);
}

char *ft_itohex(unsigned int n)
{
	int		len;
	char	*res;
	char	hexas[17];

	ft_strcpy(hexas, "0123456789abcdef");
	len = ft_hex_len(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n == 0)
	{
		res[0] = '0';
		return (res);
	}
	while (n != 0)
	{
		res[--len] = *((n % 16) + hexas);
		n /= 16;
	}
	return (res);
}

char	*ft_strcpy(char *dst, char *src)
{
	while (*src)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = 0;
	return (dst);
}
