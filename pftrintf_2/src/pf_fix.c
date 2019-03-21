#include "ft_printf.h"

char 					*pf_plus_fix(char *str)
{
	char	*buff;
	char 	*str_buff;
	int 	i;
	char	*new_str;

	if (*str == '-')
		return (str);
	i = ft_strlen(str);
	buff = (char*)malloc(sizeof(char) * i + 2);
	*buff = '+';
	new_str = buff;
	buff++;
	str_buff = str;
	while (*str_buff)
		*buff++ = *str_buff++;
	*buff = '\0';
	free (str);
	return (new_str);
}

char		*pf_accur_fixdiouxX(int i, char *str)
{
	char *buff;
	int j;
	int plus_minus;
	char *new_str;
	char *new_str_buff;

	plus_minus = 0;
	buff = str;
	if (*buff == '-' || *buff == '+')
		plus_minus = 1;
	if (i == 0 && *str == '0')
	{
		free(str);
		return (ft_strdup(""));
	}
	if ((j = (ft_strlen(buff) - plus_minus)) >= i)
		return (str);
	new_str = (char *) malloc(sizeof(char) * i + plus_minus + 1);
	*(new_str + i + plus_minus) = '\0';
	new_str_buff = new_str;
	if (plus_minus == 1)
	{
		*buff == '-' ? *new_str = '-' : 0;
		*buff == '+' ? *new_str = '+' : 0;
		new_str_buff++;
	}
	while (j != 0)
		*(new_str_buff + i-- - 1) = *(buff + --j + plus_minus);
	while ((i - plus_minus) >= 0)
		*(new_str_buff + i-- - 1) = '0';
	free(str);
	return (new_str);
}

char 					*pf_pointer_accur(int i, char *str)
{
	char	*buff;
	int 	len;
	char 	*zero;

	len = (int)ft_strlen(str);
	if (i == 0 && *str == '0')
	{
		free(str);
		return (ft_strdup(""));
	}
	if (len >= i)
		return (str);
	buff = str;
	i = i - len;
	zero = (char*)malloc(sizeof(char) * i + 1);
	zero[i] = '\0';
	len = 0;
	while (len < i)
		zero[len++] = '0';
	buff = ft_strjoin(zero, buff);
	free(str);
	free(zero);
	return (buff);
}

char 					*pf_add_one_space_before(char *str)
{
	char	*leak;
	char 	*space;

	space = ft_strdup(" ");
	leak = str;
	str = ft_strjoin(space, str);
	free(leak);
	free(space);
	return (str);
}