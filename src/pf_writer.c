//
// Created by Volodymyr DANYLIUK on 2019-03-06.
//
#include "ft_printf.h"

void 					pf_write_and_remalloc(char **str)
{
	char 	*strBack;
	char	*buff;
	size_t 	i;

	buff = *str;
	while (*buff && *buff != '%')
		buff++;
	strBack = ft_strsub(*str, 0, (i = (buff - *str)));
	write(1, strBack, i);
	g_len += i;
	free(strBack);
	strBack = ft_strdup(buff);
	free(*str);
	*str = strBack;
}

void					pf_write_flag(va_list ptr, t_type **lst)
{
	int 	i;
	t_type	*buff;

	buff = *lst;
	i = pf_type_group(buff->type);
	i == 100 ? pf_print_procent(buff) : 0;
	(i == 1 || i == 2) ? pf_print_csp(buff, ptr) : 0;
	*lst = (*lst)->next;
}

void 					pf_skip_flag_remalloc(char **str)
{
	char *buff;

	buff = *str;
	while (*buff && (pf_is_type(*buff) == 100 || pf_is_type(*buff) == 0))
	{
		buff++;
		if (pf_is_type(*buff) == 100)
			break;
	}
	if (*buff)
		buff++;
	if (*buff)
	{
		buff = ft_strdup(*str + (buff - *str));
		free(*str);
		*str = buff;
	}
	else
	{
		free(str);
		*str = "";
	}
}