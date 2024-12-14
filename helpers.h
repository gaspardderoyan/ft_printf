#ifndef HELPERS_H
# define HELPERS_H
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>

size_t				strlen_safe(const char *s);
char				*ft_itoa(int n);
char				*ft_itohex(uintptr_t n);
char				*ft_itohex_upper(uintptr_t n);
char				*ft_utoa(unsigned int n);

#endif
