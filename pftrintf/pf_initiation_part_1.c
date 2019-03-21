//
// Created by Volodymyr DANYLIUK on 2019-03-01.
//

#include "ft_printf.h"

int 	pf_is_type(char c)		//return number of type
{
	int ret;

	ret = 0;
	c == 'c' ? ret = 1 : 0;
	c == 's' ? ret = 2 : 0;
	c == 'p' ? ret = 3 : 0;
	c == 'd' ? ret = 4 : 0;
	c == 'i' ? ret = 5 : 0;
	c == 'o' ? ret = 6 : 0;
	c == 'u' ? ret = 7 : 0;
	c == 'x' ? ret = 8 : 0;
	c == 'X' ? ret = 9 : 0;
	c == '%' ? ret = 100 : 0;
	return (ret);
}

int 	pf_type_group(int c)	//Return number of type group;
{
	if (c >= 1 && c <= 2)
		return (1);
	if (c == 3)
		return (2);
	if ((c >= 4 && c <= 9))
		return (3);
	if (c == 100)
		return (100);
	return (0);
}

static t_type	*pf_add_end_list(t_type **head)
{
	t_type	*buff;

	if (*head == NULL)
	{
		*head = pf_create_type_lst();
		return (*head);
	}
	buff = *head;
	while (buff->next)
		buff = buff->next;
	buff->next = pf_create_type_lst();
	return(buff->next);
}

void	pf_parce_flag(t_type *buff, char *str)		//Записывает флаги в структуру в соответствии с группой типа
{
	int i;

	i = pf_type_group(buff->type);
	while (*str &&pf_is_type(*str) == 0)
	{
		pf_type_deafult_flags(buff, str);
		pf_type_cs_flags(buff, str);
		pf_type_diouxX_flags(buff, str);
		str++;
	}
}

void	pf_type_initiation(t_type **head, char *format)
{
	char	*buff_begin;
	char 	*buff_end;
	t_type	*type_buff;

	buff_begin = format;
	while(*buff_begin)
	{

		if (*buff_begin == '%' && *(buff_begin + 1))
		{
			type_buff = pf_add_end_list(head);
			buff_end = (buff_begin + 1);
			while (*buff_end && pf_is_type(*buff_end) == 0)
				buff_end++;
			*buff_end != '\0' ? type_buff->type = pf_is_type(*buff_end) : 0;
			buff_begin++;
			while (buff_begin != buff_end)
				pf_parce_flag(type_buff, buff_begin++);
			buff_begin++;
		}
		else
			buff_begin++;
	}
}