
#include "ft_printf.h"
#include <limits.h>

int		ft_printf(const char *format, ...)
{
	va_list			ptr;
	t_type			*head;
	t_type			*buff;
	char			*format_buff;

	head = NULL;
	g_len = 0;
	va_start(ptr, format);
	pf_type_initiation(&head, (char*)format);
	buff = head;
	format_buff = ft_strdup(format);
	while (*format_buff)
	{
		if (*format_buff != '%' || head == NULL)
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
	return (g_len);
}

int 	main(void)
{
	char 	*str;
	printf("|%#05p|\n", 0);
	ft_printf("|%#05p|\n", 0);
	printf("|%5p|\n", 0);
	ft_printf("|%5p|\n", 0);
	//system("leaks -q ft_printf");
}