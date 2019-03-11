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
	pf_type_initiation(&head, (char*)format);
	buff = head;
	format_buff = ft_strdup(format);
	while (*format_buff)
	{
		if (*format_buff != '%')
			pf_write_and_remalloc(&format_buff);
		else
		{
			pf_skip_flag_remalloc(&format_buff);
			pf_write_flag(ptr, &buff);
		}
	}
	ft_free_t_type(head);
	free(format_buff);
	va_end(ptr);
	//system("leaks -q ft_printf");
	return (g_len);
}

int 	main(void)
{
	unsigned long long int i;
	char *str = "Hello world";
	char *leak;

	printf("He%cllo w%sr%0-10%ld\n", *str, str);
	i = ft_printf("He%cllo w%sr%-10%ld\n", *str, str);
	ft_putendl(leak = ft_itoa(i));
	free(leak);
	system("leaks -q ft_printf");
	printf("a%20pa\n", str);
	ft_printf("a%20pa\n", str);
	system("leaks -q ft_printf");
	i = str;
	printf("%i", i);
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