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
		buff++;
	}
	buff = str;
	while (*buff && !ft_isdigit(*buff) && *buff != '0' && pf_is_type(*buff) == 0)
		buff++;
	if (*buff && pf_is_type(*buff) != 0 && *(buff - 1) != '.')
		type_buff->width->width = ft_atoi(buff);
}

void	pf_type_diouxX_flags(t_type *curr, char *str)
{
	char	*buff;
	t_type	*type_buff;

	buff = str;
	type_buff = curr;
	while (*buff && pf_is_type(*buff) == 0)
	{
		if (*buff == 'h' && *(buff + 1) && *(buff + 1) == 'h' &&type_buff->spec == 0)
			type_buff->spec = 2;
		if (*buff == 'l' && *(buff + 1) && *(buff + 1) == 'l' &&type_buff->spec == 0)
			type_buff->spec = 4;
		if (*buff == 'h' && type_buff->spec == 0)
			type_buff->spec = 1;
		if (*buff == 'l' && type_buff->spec == 0)
			type_buff->spec = 3;
		if (*buff == '.' && *(buff + 1) && pf_is_type(*(buff + 1) == 0))
			type_buff->accur->number = ft_atoi(buff);
		else if (*buff == '.' && *(buff + 1) == '*')
			type_buff->accur->star = 1;
		buff++;
	}
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
		buff++;
	}
}