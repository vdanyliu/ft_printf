//
// Created by Volodymyr DANYLIUK on 2019-03-06.
//
#include "ft_printf.h"

char 					*pf_write_and_remalloc(char *str)
{
	char 	*strBack;
	char	*buff;
	size_t 	i;

	buff = str;
	while (*buff && *buff != '%')
		buff++;
	strBack = ft_strsub(str, 0, (i = (buff - str)));
	write(1, strBack, i);
	g_len += i;
	free(strBack);
	strBack = ft_strdup(buff);
	free(str);
	return (strBack);
}

char 					*pf_skip_flag_remalloc(char *str)
{
	char *buff;

	buff = str;
	while (*buff && (pf_is_type(*buff) == 100 || pf_is_type(*buff) == 0))
		buff++;
	if (*buff)
		buff++;
	if (*buff)
	{
		buff = ft_strdup(str + (buff - str));
		free(str);
		return (buff);
	}
	else
	{
		free(str);
		return (ft_strdup(""));
	}
}