#ifndef TYPES_H
# define TYPES_H
# include <stdarg.h>
# include <unistd.h>

void				p_char(va_list *ptr, int *ccount);
void				p_int(va_list *ptr, int *ccount);
void				p_percent(int *ccount);
void				p_else(const char *str, int *ccount);

#endif
