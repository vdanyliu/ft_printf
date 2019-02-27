//
// Created by Volodymyr DANYLIUK on 2019-02-27.
//

#include "ft_printf.h"

int 	ft_printf(const char *format, ...)
{
	va_list ptr;

	va_start(ptr, format);
}

int 	main(void)
{
	char c;

	c = 'a';
	printf("%c\n", c);
	ft_printf("%c\n", c);
	return (0);
}