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

static void	pf_print_char(t_type *buff, char c)
{
	char	*str1;
	char 	*str2;
	size_t 	i;

	str2 = (char*)malloc(sizeof(char) * 2);
	str2[0] = c;
	str2[1] = '\0';
	str1 = pf_spaces(buff, (buff->width->width - 1));
	str1 = pf_union(buff, str1, str2);
	i = ft_strlen(str1);
	g_len += i;
	write(1, str1, i);
	free(str1);
}

static void	pf_print_string(t_type *buff, char *str)
{
	char	*str1;
	char 	*str2;
	size_t 	i;

	str2 = ft_strdup(str);
	str1 = pf_spaces(buff, (buff->width->width - ft_strlen(str2)));
	str1 = pf_union(buff, str1, str2);
	i = ft_strlen(str1);
	g_len += i;
	write(1, str1, i);
	free(str1);
}

static void pf_print_pointer(t_type *buff, unsigned long long int j)
{
	char	*str1;
	char 	*str2;
	size_t 	i;
	char 	*leak;

	str2 = pf_itoabase(j, 16);
	leak = str2;
	str2 = ft_strjoin("0x", str2);
	free(leak);
	str1 = pf_spaces(buff, (buff->width->width - ft_strlen(str2)));
	str1 = pf_union(buff, str1, str2);
	i = ft_strlen(str1);
	g_len += i;
	write(1, str1, i);
	free(str1);
}

void	pf_print_csp(t_type *buff, va_list ptr)
{
	if (buff->type == 1)
		pf_print_char(buff, va_arg(ptr, char));
	if (buff->type == 2)
		pf_print_string(buff, va_arg(ptr, char*));
	if (buff->type == 3)
		pf_print_pointer(buff, va_arg(ptr, unsigned long long int));
}