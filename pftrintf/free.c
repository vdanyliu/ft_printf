#include "ft_printf.h"

void		ft_free_t_type(t_type *head)
{
	t_type *buff;

	while (head)
	{
		buff = head->next;
		free(head->accur);
		free(head->width);
		free(head->flag);
		free(head);
		head = buff;
	}
}

char 		*pf_union(t_type *buff, char *str1, char *str2)
{
	size_t	i;
	char	*res;
	char 	*res_buff;
	char 	*str1buff;
	char 	*str2buff;

	if (str1 == NULL)
	{
		if (*str2 != '-' && *str2 != '+' && (buff->type == 4 || buff->type == 5) && buff->flag->space == 1)
			str2 = pf_add_one_space_before(str2);
		return (str2);
	}
	i = ft_strlen(str1);
	i += ft_strlen(str2);
	res = (char*)malloc(sizeof(char) * (i + 1));
	res_buff = res;
	str1buff = str1;
	str2buff = str2;
	if ((*str2 == '-' || *str2 == '+') && *str1 == '0')
		*res_buff++ = *str2buff++;
	if (buff->flag->minus == 0)
	{
		while (*str1buff)
			*(res_buff++) = *(str1buff++);
		while (*str2buff)
			*(res_buff)++ = *(str2buff++);
	}
	else
	{
		while (*str2buff)
			*res_buff++ = *str2buff++;
		while (*str1buff)
			*res_buff++ = *str1buff++;
	}
	*res_buff = '\0';
	free(str1);
	free(str2);
	return (res);
}

char 		*pf_spaces(t_type *buff, int i)
{
	char	*str;
	int 	j;
	char 	c;

	if (i <= 0)
		return (NULL);
	c = ' ';
	if (buff->flag->zero == 1)
		c = '0';
	str = (char*)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	j = 0;
	while (j < i)
		str[j++] = c;
	return (str);
}