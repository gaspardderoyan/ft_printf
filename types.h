#ifndef TYPES_H
# define TYPES_H
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

void				p_char(va_list *ptr, int *ccount);
void				p_int(va_list *ptr, int *ccount);
void				p_percent(int *ccount);
void				p_else(const char *str, int *ccount);
void				p_str(va_list *ptr, int *ccount);
void				p_ptr(va_list *ptr, int *ccount);

#endif
