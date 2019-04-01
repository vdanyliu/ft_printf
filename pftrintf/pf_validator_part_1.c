
#include "ft_printf.h"

int 	pf_any_procent(char *str)
{
	char	*buff;

	buff = str;
	while (*buff)
	{
		if (*buff == '%')
			return (1);
		buff++;
	}
	return (0);
}