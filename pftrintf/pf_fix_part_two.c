//
// Created by Volodymyr DANYLIUK on 2019-03-22.
//

#include "ft_printf.h"

void					pf_hesh_replace(char *str)
{
	char	*buff;
	char 	tmp;

	buff = str;
	while (*buff && (*buff != 'x' && *buff != 'X'))
		buff++;
	if (*buff)
	{
		tmp = *buff;
		*buff = *(str + 1);
		*(str + 1) = tmp;
	}
}

char 					*pf_space_fix(char *str)
{
	char	*buff;
	char 	*str_buff;
	int 	i;
	char	*new_str;

	if (*str == '-' || *str == '+')
		return (str);
	i = ft_strlen(str);
	buff = (char*)malloc(sizeof(char) * i + 2);
	*buff = ' ';
	new_str = buff;
	buff++;
	str_buff = str;
	while (*str_buff)
		*buff++ = *str_buff++;
	*buff = '\0';
	free (str);
	return (new_str);
}

void					pf_bonus_rules(t_type *buff)
{
	if (buff->flag->minus)
		buff->flag->zero = 0;
	if (buff->type > 10 && buff->type <= 20)
	{
		buff->type = buff->type - 10;
		buff->spec = 4;
	}
	if (buff->type == 10)
		buff->accur->number == -1 ? buff->accur->number = 6 : 0;
}