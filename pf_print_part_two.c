#include "ft_printf.h"

static void				pf_print_dexs(t_type *buff, signed long long int j)
{
	char	*str1;
	char 	*str2;
	size_t 	i;
	char 	*leak;

	buff->spec == 1 ? str2 = pf_itoabase((signed short)j, 10) : 0;
	buff->spec == 2 ? str2 = pf_itoabase((signed char)j, 10) : 0;
	buff->spec == 3 ? str2 = pf_itoabase((signed long)j, 10) : 0;
	buff->spec == 4 ? str2 = pf_itoabase(j, 10) : 0;
	buff->spec == 0 ? str2 = pf_itoabase((signed int)j, 10) : 0;
	str1 = pf_spaces(buff, (buff->width->width - ft_strlen(str2)));
	str1 = pf_union(buff, str1, str2);
	i = ft_strlen(str1);
	g_len += i;
	write(1, str1, i);
	free(str1);
}

static void				pf_print_dexuns(t_type *buff, unsigned long long int j)
{
	char	*str1;
	char 	*str2;
	size_t 	i;
	char 	*leak;

	buff->spec == 1 ? str2 = pf_itoabaseun((unsigned short)j, 10) : 0;
	buff->spec == 2 ? str2 = pf_itoabaseun((unsigned char)j, 10) : 0;
	buff->spec == 3 ? str2 = pf_itoabaseun((unsigned long)j, 10) : 0;
	buff->spec == 4 ? str2 = pf_itoabaseun(j, 10) : 0;
	buff->spec == 0 ? str2 = pf_itoabaseun((unsigned int)j, 10) : 0;
	//str1 = pf_accur_fixdiouxX(buff->accur->number, str1);
	str1 = pf_spaces(buff, (buff->width->width - ft_strlen(str2)));
	str1 = pf_union(buff, str1, str2);
	i = ft_strlen(str1);
	g_len += i;
	write(1, str1, i);
	free(str1);
}

void					pf_print_diouxX(t_type *buff, va_list ptr)
{
	if (buff->type == 4 || buff->type == 5)
		pf_print_dexs(buff, va_arg(ptr, signed long long int));
	if (buff->type == 7)
		pf_print_dexuns(buff, va_arg(ptr, unsigned long long int));
}