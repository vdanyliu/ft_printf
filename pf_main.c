//
// Created by Volodymyr DANYLIUK on 2019-02-27.
//

#include "ft_printf.h"

int 	ft_printf(const char *format, ...)
{
	va_list			ptr;
	static t_type	*head = NULL;

	va_start(ptr, format);
	if (pf_any_procent(format) == 0)
	{
		write(1, format, ft_strlen(format));
		return ((int)ft_strlen(format));
	}
	else
	{
		pf_type_initiation(head, format);
	}
	return (0);
}

int 	main(void)
{
	char *str = "Hello world";

	printf("Hello\n%s", str);
	//ft_printf("Hello world\n", c);
	return (0);
}



//int        ft_printf(const char *format, ...)
//{
//	size_t    i;
//	va_list    ptr;
//	t_lst    *lst;
//	char     c;
//
//	g_len = 0;
//	g_count = g_len;
//	ft_bzero(g_buff, 8192);
//	va_start(ptr, format);
//	i = 0;
//	while (format[i])
//	{
//		if (format[i] == '%')
//		{
//			c = (char)va_arg(ptr, int);
//			i++;
//			g_flag = 0;
//			lst = create_list(format, &i, ptr);
//			read_specif(lst, ptr);
//			free(lst);
//		}
//		else
//			print_format_no_spec(format, &i);
//	}
//	va_end(ptr);
//	ft_print_buff(g_buff);
//	return (g_len);
//}