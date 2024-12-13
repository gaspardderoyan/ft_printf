#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <unistd.h>

void				choose_fun(va_list *ptr, const char **str, int *ccount);
int					ft_printf(const char *str, ...);

#endif
