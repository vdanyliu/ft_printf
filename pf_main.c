//
// Created by Volodymyr DANYLIUK on 2019-02-27.
//

#include "ft_printf.h"

int 	ft_printf(const char *format, ...)
{
	va_list			ptr;
	t_type			*head;
	t_type			*buff;
	char 			*format_buff;


	head = NULL;
	g_len = 0;
	va_start(ptr, format);
	if (pf_any_procent((char*)format) == 0)
	{
		write(1, format, g_len = ft_strlen((char*)format));
		return (g_len);
	}
	else
		pf_type_initiation(&head, (char*)format);
	buff = head;
	format_buff = ft_strdup(format);
	while (*format_buff)
	{
		if (*format_buff != '%')
			format_buff = pf_write_and_remalloc(format_buff);
		else
		{
			format_buff = pf_skip_flag_remalloc(format_buff);
		}
	}
	return (g_len);
}

int 	main(void)
{
	int i;
	char *str = "Hello world";

	printf("He%llo\n", str);
	i = ft_printf("He%llo world\n", str);
	ft_putendl(ft_itoa(i));
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