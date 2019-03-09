#include "ft_printf.h"

void	pf_print_procent(t_type *buff)
{
	char	*str1;
	char 	*str2;
	size_t 	i;

	str2 = (char*)malloc(sizeof(char) * 2);
	str2[0] = '%';
	str2[1] = '\0';
	str1 = pf_spaces(buff, (buff->width->width - 1));
	str1 = pf_union(buff, str1, str2);
	i = ft_strlen(str1);
	g_len += i;
	write(1, str1, i);
	free(str1);
}