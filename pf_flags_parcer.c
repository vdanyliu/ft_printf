//
// Created by Volodymyr DANYLIUK on 2019-03-04.
//
#include "ft_printf.h"

void	pf_type_deafult_flags(t_type *curr, char *str)
{
	char	*buff;
	t_type	*type_buff;

	buff = str;
	type_buff = curr;
	while (*buff && pf_is_type(*buff) == 0)
	{
		if (*(buff - 1) == '%')
			*buff == '0' ? type_buff->flag->zero = 1 : 0;
		*buff == '-' ? type_buff->flag->minus = 1 : 0;
		*buff == '+' ? type_buff->flag->plus = 1 : 0;
		*buff == ' ' ? type_buff->flag->space = 1 : 0;
	}
	buff = str;
	while (*buff && !ft_isdigit(*buff) && *buff != '0' && pf_is_type(*buff) == 0)
		buff++;
	if (*buff && pf_is_type(*buff) != 0 && *(buff - 1) != '.')
		type_buff->width->width = ft_atoi(buff);
}

void					pf_type_cs_flags(t_type *curr, char *str)
{
	char	*buff;
	t_type	*type_buff;

	buff = str;
	type_buff = curr;
	while (*buff && pf_is_type(*buff) == 0)
	{
		if (*buff == 'l')
			type_buff->spec = 1;
	}
}