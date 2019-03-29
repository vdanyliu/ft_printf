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

int     main(void)
{
	//printf("34)\n{%.1f}\n", 3.25);
	//printf("%.4f\n", 2.22286);
//	printf("|%.2f|\n", 2.2551);
//	ft_printf("|%.2f|\n", 2.2551);
//	printf("38)\n{%f}\n", 2.050000001);
//	ft_printf("{%f}\n\n", 2.050000001);

//	printf("49)\n{%f}\n", 0.0/0.0);
//	ft_printf("{%f}\n\n", 0.0/0.0);
//
	printf("50)\n{%f}\n", 3.0/0.0);
	ft_printf("{%f}\n\n", 3.0/0.0);
//
//	printf("51)\n{%f}\n", -3.0/0.0);
//	ft_printf("{%f}\n\n", -3.0/0.0);
    return (0);
}

//#include <stdio.h>
//#include <stddef.h>
//#include <locale.h>
//#include <limits.h>
//#include <errno.h>
//
//#define RED "\x1b[31m"
//#define NORM "\x1b[0m"
//
////Testing macro - dont change!
//#define PRINTF(...){\
//		int ret = 0,ret2 = 0;\
//		printf("Args:\t%s\n", #__VA_ARGS__);\
//		printf("Origin:\t");ret = printf(__VA_ARGS__);\
//		printf("\tret: %d\n",ret);fflush(stdout);\
//		ft_printf("    Ft:\t");ret2 = ft_printf(__VA_ARGS__);\
//		printf("\t%sret: %d"NORM"\n",(ret == ret2) ? NORM : RED, ret2);\
//		printf("\n");fflush(stdout);\
//}
//#define TITLE(...){printf("\033[1m\n");printf(__VA_ARGS__);printf("\n\033[0m");}
//
////Include your printf here!
//#include "ft_printf.h"
//
////Test switchers - comment some of then to turn the tests off
//#define	CHAR		//aka chars
//#define	PER			//aka percent(%)
//#define	NUM			//aka numbers
//#define	PTR			//aka pointers
////#define	STRANGE		//aka undefined tests
//#define STR			//aka strings
//#define WSTR		//aka wide strings
//#define	LENGTH		//aka hh, h, l ,ll , z, j
//
//int	main(void)
//{
//	setlocale(LC_CTYPE, "");
//#ifdef CHAR
//	TITLE("Char options:\n");
//	{
//		char a = ' ';
//		for (a = ' '; a <' ' + 60 ; a+=15)
//		PRINTF("|%-2c|(%3d)\t|%-2c|(%3d)\t|%-2c|(%3d)", a, a, a+5,a+5,a+10,a+10);
//		PRINTF("|%-2.3c|(%3d)\t|%-2.5c|(%3d)\t|%-2.0c|(%3d)", a, a, a+5,a+5,a+10,a+10);
//		PRINTF("|%+3c|(%3d)\t|%+3c|(%3d)\t|%+c|(%3d)", a, a, a+5, a+5, a+10, a+10);
//		PRINTF("|%3.4c|(%3d)\t|%+3.4c|(%3d)\t|%.4c|(%3d)", a, a, a+5, a+5, a+10, a+10);
//		PRINTF("|%-3c|\t|%3c|\t|%c|\t|%-03c|\t|%03c|\t|%.c|\t|%.5c|", 0,0,0,0,0,0,0,0,0);
//	}
//#endif
//
//#ifdef PER
//	TITLE("Percent options:\n");
//	PRINTF("|%-6%|   |%6%|   |%6.2%|   |%-06%|   |%-06.3%|");
//#endif
//
//#ifdef STR
//	TITLE("Strings:\n");
//	PRINTF("|%s|", NULL);
//	PRINTF("|%s|", "ПрэвЭд!");
//	PRINTF("|%s|\t","ç±³");
//	TITLE("String options(field width, presicion and justification):\n");
//	{
//		const char A[] = "this is tEEEEst!";
//		PRINTF("|%5.3s|\t\t|%3.5s|\t|%7s|\t|%7.3s|",A, A,A,NULL);
//		PRINTF("|%07.5s|\t|%02.5s|\t|%.10s|\t\t|%.5s|\t",A,A,A, "");
//		PRINTF("|%-7.5s|\t|%-2.5s|\t|%-.10s|\t\t|%-.5s|\t",A,A,A, "");
//		PRINTF("|%-07.5s|\t|%-02.5s|\t|%-020s|\t|%-0.5s|\t",A,A,A, "");
//	}
//#endif
//
//#ifdef PTR
//	TITLE("Pointer options(field width, presicioin and justification):\n");
//	{
//		char *ptr_c = (char*)malloc(sizeof(char));
//		int ptr_i = 43;
//		long ptr_l = 874748;
//		PRINTF("|%.0p|\t\t|%6p|\t\t|%6.p|\t|%10.6p|", NULL,NULL,NULL,NULL);
//		PRINTF("|%12p||%17p|\t|%-22p|", ptr_c, &ptr_i, &ptr_l);
//		PRINTF("|%.0p||%6p|\t|%6.p||%.20p|", &ptr_l, &ptr_l, &ptr_l,&ptr_l);
//		free(ptr_c);
//	}
//#endif
//
//#ifdef NUM
//	TITLE("Number options(field width and justification):\n");
//	printf("   |i|:\n");
//	PRINTF("\t|%12i|\t|%12i|\t|%12i|", INT_MIN, INT_MAX,0);
//	PRINTF("\t|%012i|\t|%-12i|\t|%012i|",-42,42,42);
//	printf("\n   |d|:\n");
//	PRINTF("\t|%12d|\t|%12d|\t|%12d|", INT_MIN, INT_MAX,0);
//	PRINTF("\t|%012d|\t|%-12d|\t|%012d|",-42,42,42);
//	printf("\n   |u|:\n");
//	PRINTF("\t|%12u|\t|%12u|\t|%12u|", INT_MIN, INT_MAX,0);
//	PRINTF("\t|%012u|\t|%-12u|\t|%012u|",-42,42,42);
//	printf("\n   |o|:\n");
//	PRINTF("\t|%12o|\t|%12o|\t|%12o|", INT_MIN, INT_MAX,0);
//	PRINTF("\t|%012o|\t|%-12o|\t|%012o|",-42,42,42);
//	printf("\n   |x|:\n");
//	PRINTF("\t|%12x|\t|%12x|\t|%12x|", INT_MIN, INT_MAX,0);
//	PRINTF("\t|%012x|\t|%-12x|\t|%012x|",-42,42,42);
//	printf("\n   |X|:\n");
//	PRINTF("\t|%12X|\t|%12X|\t|%12X|", INT_MIN, INT_MAX,0);
//	PRINTF("\t|%012X|\t|%-12X|\t|%012X|",-42,42,42);
//	TITLE("Number options(field width, presicion and -):\n");
//	{
//		int nmb = 4235;
//#define CNV "i"
//		printf("\n   |"CNV"|:\n");
//		PRINTF("|%1.1"CNV"|\t\t|%5.1"CNV"|\t\t|%5.3"CNV"|\t\t|%1.5"CNV"|\t",nmb, nmb, nmb, nmb);
//		PRINTF("|%1.1"CNV"|\t\t|%5.1"CNV"|\t\t|%5.3"CNV"|\t\t|%1.5"CNV"|",-nmb, -nmb, -nmb, -nmb);
//		PRINTF("|%3.5"CNV"|\t\t|%3.5"CNV"|\t|%07.5"CNV"|\t|%07.5"CNV"|",nmb, -nmb, nmb, -nmb);
//		PRINTF("|%8.5"CNV"|\t|%8.5"CNV"|\t|%08"CNV"|\t|%08"CNV"|",nmb, -nmb, nmb, -nmb);
//		PRINTF("|%-.10"CNV"|\t|%.-10"CNV"|\t|%-15.-10"CNV"|\t|%15.-10"CNV"|",42,42,42,42);
//		PRINTF("|%-12.8.5"CNV"|\t|%12.-8.5"CNV"|\t|%-12.-8.5"CNV"|\t|%-12.-8.-5"CNV"|\t",42,42,42,42);
//		PRINTF("|%7-.5"CNV"|\t|%-7-.5"CNV"|\t|%7.5-"CNV"|\t|%-7.-5-"CNV"|\t", 42,42,42,42);
//		PRINTF("|%12.8.10.6"CNV"|\t|%20.8.-12.6"CNV"|\t|%20.8.12.-6"CNV"||%20.-5.12.3"CNV"|\t|%10.8.12.6-"CNV"|",42,42,42,42,42);
//		PRINTF("|%."CNV" %.0"CNV" %0."CNV" %0.0"CNV"|\t\t|%"CNV" %.2"CNV" %2."CNV" %2.2"CNV"|\t\t\t\t",0,0,0,0,0,0,0,0);
//	}
//	{
//		int nmb = 4235;
//#define CNV "d"
//		printf("\n   |"CNV"|:\n");
//		PRINTF("|%1.1"CNV"|\t\t|%5.1"CNV"|\t\t|%5.3"CNV"|\t\t|%1.5"CNV"|\t",nmb, nmb, nmb, nmb);
//		PRINTF("|%1.1"CNV"|\t\t|%5.1"CNV"|\t\t|%5.3"CNV"|\t\t|%1.5"CNV"|",-nmb, -nmb, -nmb, -nmb);
//		PRINTF("|%3.5"CNV"|\t\t|%3.5"CNV"|\t|%07.5"CNV"|\t|%07.5"CNV"|",nmb, -nmb, nmb, -nmb);
//		PRINTF("|%8.5"CNV"|\t|%8.5"CNV"|\t|%08"CNV"|\t|%08"CNV"|",nmb, -nmb, nmb, -nmb);
//		PRINTF("|%-.10"CNV"|\t|%.-10"CNV"|\t|%-15.-10"CNV"|\t|%15.-10"CNV"|",42,42,42,42);
//		PRINTF("|%-12.8.5"CNV"|\t|%12.-8.5"CNV"|\t|%-12.-8.5"CNV"|\t|%-12.-8.-5"CNV"|\t",42,42,42,42);
//		PRINTF("|%7-.5"CNV"|\t|%-7-.5"CNV"|\t|%7.5-"CNV"|\t|%-7.-5-"CNV"|\t", 42,42,42,42);
//		PRINTF("|%12.8.10.6"CNV"|\t|%20.8.-12.6"CNV"|\t|%20.8.12.-6"CNV"||%20.-5.12.3"CNV"|\t|%10.8.12.6-"CNV"|",42,42,42,42,42);
//		PRINTF("|%."CNV" %.0"CNV" %0."CNV" %0.0"CNV"|\t\t|%"CNV" %.2"CNV" %2."CNV" %2.2"CNV"|\t\t\t\t",0,0,0,0,0,0,0,0);
//	}
//	{
//		int nmb = 4235;
//#define CNV "u"
//		printf("\n   |"CNV"|:\n");
//		PRINTF("|%1.1"CNV"|\t\t|%5.1"CNV"|\t\t|%5.3"CNV"|\t\t|%1.5"CNV"|\t",nmb, nmb, nmb, nmb);
//		PRINTF("|%1.1"CNV"|\t|%5.1"CNV"|\t|%5.3"CNV"|\t|%1.5"CNV"|",-nmb, -nmb, -nmb, -nmb);
//		PRINTF("|%3.5"CNV"|\t\t|%3.5"CNV"|\t|%07.5"CNV"|\t|%07.5"CNV"|",nmb, -nmb, nmb, -nmb);
//		PRINTF("|%8.5"CNV"|\t|%8.5"CNV"|\t|%08"CNV"|\t|%08"CNV"|",nmb, -nmb, nmb, -nmb);
//		PRINTF("|%-.10"CNV"|\t|%.-10"CNV"|\t|%-15.-10"CNV"|\t|%15.-10"CNV"|",42,42,42,42);
//		PRINTF("|%-12.8.5"CNV"|\t|%12.-8.5"CNV"|\t|%-12.-8.5"CNV"|\t|%-12.-8.-5"CNV"|\t",42,42,42,42);
//		PRINTF("|%7-.5"CNV"|\t|%-7-.5"CNV"|\t|%7.5-"CNV"|\t|%-7.-5-"CNV"|\t", 42,42,42,42);
//		PRINTF("|%12.8.10.6"CNV"|\t|%20.8.-12.6"CNV"|\t|%20.8.12.-6"CNV"||%20.-5.12.3"CNV"|\t|%10.8.12.6-"CNV"|",42,42,42,42,42);
//		PRINTF("|%."CNV" %.0"CNV" %0."CNV" %0.0"CNV"|\t\t|%"CNV" %.2"CNV" %2."CNV" %2.2"CNV"|\t\t\t\t",0,0,0,0,0,0,0,0);
//	}
//	{
//		int nmb = 4235;
//#define CNV "o"
//		printf("\n   |"CNV"|:\n");
//		PRINTF("|%1.1"CNV"|\t\t|%5.1"CNV"|\t\t|%5.3"CNV"|\t\t|%1.5"CNV"|\t",nmb, nmb, nmb, nmb);
//		PRINTF("|%1.1"CNV"|\t|%5.1"CNV"|\t|%5.3"CNV"|\t|%1.5"CNV"|",-nmb, -nmb, -nmb, -nmb);
//		PRINTF("|%3.5"CNV"|\t\t|%3.5"CNV"|\t|%07.5"CNV"|\t|%07.5"CNV"|",nmb, -nmb, nmb, -nmb);
//		PRINTF("|%8.5"CNV"|\t|%8.5"CNV"|\t|%08"CNV"|\t|%08"CNV"|",nmb, -nmb, nmb, -nmb);
//		PRINTF("|%-.10"CNV"|\t|%.-10"CNV"|\t|%-15.-10"CNV"|\t|%15.-10"CNV"|",42,42,42,42);
//		PRINTF("|%-12.8.5"CNV"|\t|%12.-8.5"CNV"|\t|%-12.-8.5"CNV"|\t|%-12.-8.-5"CNV"|\t",42,42,42,42);
//		PRINTF("|%7-.5"CNV"|\t|%-7-.5"CNV"|\t|%7.5-"CNV"|\t|%-7.-5-"CNV"|\t", 42,42,42,42);
//		PRINTF("|%12.8.10.6"CNV"|\t|%20.8.-12.6"CNV"|\t|%20.8.12.-6"CNV"||%20.-5.12.3"CNV"|\t|%10.8.12.6-"CNV"|",42,42,42,42,42);
//		PRINTF("|%."CNV" %.0"CNV" %0."CNV" %0.0"CNV"|\t\t|%"CNV" %.2"CNV" %2."CNV" %2.2"CNV"|\t\t\t\t",0,0,0,0,0,0,0,0);
//	}
//	{
//		int nmb = 4235;
//#define CNV "x"
//		printf("\n   |"CNV"|:\n");
//		PRINTF("|%1.1"CNV"|\t\t|%5.1"CNV"|\t\t|%5.3"CNV"|\t\t|%1.5"CNV"|\t",nmb, nmb, nmb, nmb);
//		PRINTF("|%1.1"CNV"|\t|%5.1"CNV"|\t|%5.3"CNV"|\t|%1.5"CNV"|",-nmb, -nmb, -nmb, -nmb);
//		PRINTF("|%3.5"CNV"|\t\t|%3.5"CNV"|\t|%07.5"CNV"|\t|%07.5"CNV"|",nmb, -nmb, nmb, -nmb);
//		PRINTF("|%8.5"CNV"|\t|%8.5"CNV"|\t|%08"CNV"|\t|%08"CNV"|",nmb, -nmb, nmb, -nmb);
//		PRINTF("|%-.10"CNV"|\t|%.-10"CNV"|\t|%-15.-10"CNV"|\t|%15.-10"CNV"|",42,42,42,42);
//		PRINTF("|%-12.8.5"CNV"|\t|%12.-8.5"CNV"|\t|%-12.-8.5"CNV"|\t|%-12.-8.-5"CNV"|\t",42,42,42,42);
//		PRINTF("|%7-.5"CNV"|\t|%-7-.5"CNV"|\t|%7.5-"CNV"|\t|%-7.-5-"CNV"|\t", 42,42,42,42);
//		PRINTF("|%12.8.10.6"CNV"|\t|%20.8.-12.6"CNV"|\t|%20.8.12.-6"CNV"||%20.-5.12.3"CNV"|\t|%10.8.12.6-"CNV"|",42,42,42,42,42);
//		PRINTF("|%."CNV" %.0"CNV" %0."CNV" %0.0"CNV"|\t\t|%"CNV" %.2"CNV" %2."CNV" %2.2"CNV"|\t\t\t\t",0,0,0,0,0,0,0,0);
//	}
//	{
//		int nmb = 4235;
//#define CNV "X"
//		printf("\n   |"CNV"|:\n");
//		PRINTF("|%1.1"CNV"|\t\t|%5.1"CNV"|\t\t|%5.3"CNV"|\t\t|%1.5"CNV"|\t",nmb, nmb, nmb, nmb);
//		PRINTF("|%1.1"CNV"|\t|%5.1"CNV"|\t|%5.3"CNV"|\t|%1.5"CNV"|",-nmb, -nmb, -nmb, -nmb);
//		PRINTF("|%3.5"CNV"|\t\t|%3.5"CNV"|\t|%07.5"CNV"|\t|%07.5"CNV"|",nmb, -nmb, nmb, -nmb);
//		PRINTF("|%8.5"CNV"|\t|%8.5"CNV"|\t|%08"CNV"|\t|%08"CNV"|",nmb, -nmb, nmb, -nmb);
//		PRINTF("|%-.10"CNV"|\t|%.-10"CNV"|\t|%-15.-10"CNV"|\t|%15.-10"CNV"|",42,42,42,42);
//		PRINTF("|%-12.8.5"CNV"|\t|%12.-8.5"CNV"|\t|%-12.-8.5"CNV"|\t|%-12.-8.-5"CNV"|\t",42,42,42,42);
//		PRINTF("|%7-.5"CNV"|\t|%-7-.5"CNV"|\t|%7.5-"CNV"|\t|%-7.-5-"CNV"|\t", 42,42,42,42);
//		PRINTF("|%12.8.10.6"CNV"|\t|%20.8.-12.6"CNV"|\t|%20.8.12.-6"CNV"||%20.-5.12.3"CNV"|\t|%10.8.12.6-"CNV"|",42,42,42,42,42);
//		PRINTF("|%."CNV" %.0"CNV" %0."CNV" %0.0"CNV"|\t\t|%"CNV" %.2"CNV" %2."CNV" %2.2"CNV"|\t\t\t\t",0,0,0,0,0,0,0,0);
//	}
////Flag + - 0 and space
//	TITLE("Number options(field width, justification, +, space and 0):\n");
//	{
//		int nmb = 42;
//#define CNV "i"
//		printf("\n   |"CNV"|:\n");
//		PRINTF("|%-11-0"CNV"|\t|%-0+11"CNV"|\t|%11+"CNV"|\t|%-11+"CNV"|\t|%0 "CNV"|",nmb,nmb,nmb,nmb,nmb);nmb *= -1;
//		PRINTF("|%-11-0"CNV"|\t|%-0+11"CNV"|\t|%11+"CNV"|\t|%-11+"CNV"|\t|%0 "CNV"|",nmb,nmb,nmb,nmb,nmb);nmb *= -1;
//	}
//	{
//		int nmb = 42;
//#define CNV "d"
//		printf("\n   |"CNV"|:\n");
//		PRINTF("|%-11-0"CNV"|\t|%-0+11"CNV"|\t|%11+"CNV"|\t|%-11+"CNV"|\t|%0 "CNV"|",nmb,nmb,nmb,nmb,nmb);nmb *= -1;
//		PRINTF("|%-11-0"CNV"|\t|%-0+11"CNV"|\t|%11+"CNV"|\t|%-11+"CNV"|\t|%0 "CNV"|",nmb,nmb,nmb,nmb,nmb);nmb *= -1;
//	}
//	{
//		int nmb = 42;
//#define CNV "u"
//		printf("\n   |"CNV"|:\n");
//		PRINTF("|%-11-0"CNV"|\t|%-0+11"CNV"|\t|%11+"CNV"|\t|%-11+"CNV"|\t|%0 "CNV"|\t",nmb,nmb,nmb,nmb,nmb);nmb *= -1;
//		PRINTF("|%-11-0"CNV"|\t|%-0+11"CNV"|\t|%11+"CNV"|\t|%-11+"CNV"|\t|%0 "CNV"|",nmb,nmb,nmb,nmb,nmb);nmb *= -1;
//	}
//	{
//		int nmb = 42;
//#define CNV "o"
//		printf("\n   |"CNV"|:\n");
//		PRINTF("|%-11-0"CNV"|\t|%-0+11"CNV"|\t|%11+"CNV"|\t|%-11+"CNV"|\t|%0 "CNV"|\t",nmb,nmb,nmb,nmb,nmb);nmb *= -1;
//		PRINTF("|%-11-0"CNV"|\t|%-0+11"CNV"|\t|%11+"CNV"|\t|%-11+"CNV"|\t|%0 "CNV"|",nmb,nmb,nmb,nmb,nmb);nmb *= -1;
//	}
//	{
//		int nmb = 42;
//#define CNV "x"
//		printf("\n   |"CNV"|:\n");
//		PRINTF("|%-11-0"CNV"|\t|%-0+11"CNV"|\t|%11+"CNV"|\t|%-11+"CNV"|\t|%0 "CNV"|\t",nmb,nmb,nmb,nmb,nmb);nmb *= -1;
//		PRINTF("|%-11-0"CNV"|\t|%-0+11"CNV"|\t|%11+"CNV"|\t|%-11+"CNV"|\t|%0 "CNV"|",nmb,nmb,nmb,nmb,nmb);nmb *= -1;
//	}
//	{
//		int nmb = 42;
//#define CNV "X"
//		printf("\n   |"CNV"|:\n");
//		PRINTF("|%-11-0"CNV"|\t|%-0+11"CNV"|\t|%11+"CNV"|\t|%-11+"CNV"|\t|%0 "CNV"|\t",nmb,nmb,nmb,nmb,nmb);nmb *= -1;
//		PRINTF("|%-11-0"CNV"|\t|%-0+11"CNV"|\t|%11+"CNV"|\t|%-11+"CNV"|\t|%0 "CNV"|",nmb,nmb,nmb,nmb,nmb);nmb *= -1;
//	}
////Flag # for X x and o and O and i
//	TITLE("Number options(field width, presicion, justification and #):\n");
//	{
//# define CNV "o"
//		printf("\n   |"CNV"|:\n");
//		PRINTF("|%#6"CNV"|\t|%#-12"CNV"|\t|%#"CNV"|\t|%#09"CNV"|\t|%#02"CNV"|\t", 8400,8400,0,8400,8400);
//		PRINTF("|%#6.7"CNV"|\t|%#-12.7"CNV"|\t|%#.7"CNV"|\t|%#09.7"CNV"|\t|%#02.7"CNV"|", 8400,8400,0,8400,8400);
//		PRINTF("|%#6.2"CNV"|\t|%#-12.2"CNV"|\t|%#.3"CNV"|\t\t|%#09.2"CNV"|\t|%#02.2"CNV"|", 8400,8400,0,8400,8400);
//		PRINTF("|%-#13.10"CNV"|\t|%-12#.10"CNV"|\t|%-13.10#"CNV"|\t|%-13.-9#"CNV"|\t", 25,25,25,25);
//	}
//	{
//# define CNV "x"
//		printf("\n   |"CNV"|:\n");
//		PRINTF("|%#6"CNV"|\t|%#-12"CNV"|\t|%#"CNV"|\t\t|%#09"CNV"|\t|%#02"CNV"|", 8400,8400,0,8400,8400);
//		PRINTF("|%#6.7"CNV"|\t|%#-12.7"CNV"|\t|%#.7"CNV"|\t|%#09.7"CNV"|\t|%#02.7"CNV"|", 8400,8400,0,8400,8400);
//		PRINTF("|%#6.2"CNV"|\t|%#-12.2"CNV"|\t|%#.3"CNV"|\t\t|%#09.2"CNV"|\t|%#02.2"CNV"|", 8400,8400,0,8400,8400);
//		PRINTF("|%-#13.10"CNV"|\t|%-12#.10"CNV"|\t|%-13.10#"CNV"|\t|%-13.-9#"CNV"|\t", 25,25,25,25);
//	}
//	{
//# define CNV "X"
//		printf("\n   |"CNV"|:\n");
//		PRINTF("|%#6"CNV"|\t|%#-12"CNV"|\t|%#"CNV"|\t\t|%#09"CNV"|\t|%#02"CNV"|", 8400,8400,0,8400,8400);
//		PRINTF("|%#6.7"CNV"|\t|%#-12.7"CNV"|\t|%#.7"CNV"|\t|%#09.7"CNV"|\t|%#02.7"CNV"|", 8400,8400,0,8400,8400);
//		PRINTF("|%#6.2"CNV"|\t|%#-12.2"CNV"|\t|%#.3"CNV"|\t\t|%#09.2"CNV"|\t|%#02.2"CNV"|", 8400,8400,0,8400,8400);
//		PRINTF("|%-#13.10"CNV"|\t|%-12#.10"CNV"|\t|%-13.10#"CNV"|\t|%-13.-9#"CNV"|\t", 25,25,25,25);
//	}
//	{
//# define CNV "i"
//		printf("\n   |"CNV"|:\n");
//		PRINTF("|%#6"CNV"|\t|%#-12"CNV"|\t|%#"CNV"|\t\t|%#09"CNV"|\t|%#02"CNV"|\t", 8400,8400,0,8400,8400);
//		PRINTF("|%#6.7"CNV"|\t|%#-12.7"CNV"|\t|%#.7"CNV"|\t|%#09.7"CNV"|\t|%#02.7"CNV"|", 8400,8400,0,8400,8400);
//		PRINTF("|%#6.2"CNV"|\t|%#-12.2"CNV"|\t|%#.3"CNV"|\t\t|%#09.2"CNV"|\t|%#02.2"CNV"|\t", 8400,8400,0,8400,8400);
//		PRINTF("|%-#13.10"CNV"|\t|%-12#.10"CNV"|\t|%-13.10#"CNV"|\t|%-13.-9#"CNV"|\t", 25,25,25,25);
//	}
//	{
//# define CNV "d"
//		printf("\n   |"CNV"|:\n");
//		PRINTF("|%#6"CNV"|\t|%#-12"CNV"|\t|%#"CNV"|\t\t|%#09"CNV"|\t|%#02"CNV"|\t", 8400,8400,0,8400,8400);
//		PRINTF("|%#6.7"CNV"|\t|%#-12.7"CNV"|\t|%#.7"CNV"|\t|%#09.7"CNV"|\t|%#02.7"CNV"|", 8400,8400,0,8400,8400);
//		PRINTF("|%#6.2"CNV"|\t|%#-12.2"CNV"|\t|%#.3"CNV"|\t\t|%#09.2"CNV"|\t|%#02.2"CNV"|\t", 8400,8400,0,8400,8400);
//		PRINTF("|%-#13.10"CNV"|\t|%-12#.10"CNV"|\t|%-13.10#"CNV"|\t|%-13.-9#"CNV"|\t", 25,25,25,25);
//	}
//	{
//# define CNV "u"
//		printf("\n   |"CNV"|:\n");
//		PRINTF("|%#6"CNV"|\t|%#-12"CNV"|\t|%#"CNV"|\t\t|%#09"CNV"|\t|%#02"CNV"|\t", 8400,8400,0,8400,8400);
//		PRINTF("|%#6.7"CNV"|\t|%#-12.7"CNV"|\t|%#.7"CNV"|\t|%#09.7"CNV"|\t|%#02.7"CNV"|", 8400,8400,0,8400,8400);
//		PRINTF("|%#6.2"CNV"|\t|%#-12.2"CNV"|\t|%#.3"CNV"|\t\t|%#09.2"CNV"|\t|%#02.2"CNV"|\t", 8400,8400,0,8400,8400);
//		PRINTF("|%-#13.10"CNV"|\t|%-12#.10"CNV"|\t|%-13.10#"CNV"|\t|%-13.-9#"CNV"|\t", 25,25,25,25);
//	}
//#endif
//#ifdef LENGTH
//	TITLE("Number options(field width and length modifiers):\n");
//	{
//# define CNV "i"
//		printf("\n   |"CNV"|:\n");
//		PRINTF("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%20j"CNV"|\t|%10z"CNV"|\t|%10"CNV"|", LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,-2,LONG_MAX);
//		PRINTF("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%20j"CNV"|\t|%10z"CNV"|\t|%10"CNV"|", LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN,-2,LONG_MIN);
//	}
//	{
//# define CNV "d"
//		printf("\n   |"CNV"|:\n");
//		PRINTF("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%20j"CNV"|\t|%10z"CNV"|\t|%10"CNV"|", LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,-2,LONG_MAX);
//		PRINTF("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%20j"CNV"|\t|%10z"CNV"|\t|%10"CNV"|", LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN,-2,LONG_MIN);
//	}
//	{
//# define CNV "u"
//		printf("\n   |"CNV"|:\n");
//		PRINTF("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%10"CNV"|", LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX);
//		PRINTF("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%10"CNV"|", LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN);
//	}
//	{
//# define CNV "o"
//		printf("\n   |"CNV"|:\n");
//		PRINTF("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%10"CNV"|", LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX);
//		PRINTF("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%10"CNV"|", LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN);
//	}
//	{
//# define CNV "x"
//		printf("\n   |"CNV"|:\n");
//		PRINTF("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%10"CNV"|", LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX);
//		PRINTF("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%10"CNV"|", LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN);
//	}
//	{
//# define CNV "X"
//		printf("\n   |"CNV"|:\n");
//		PRINTF("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%10"CNV"|", LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX);
//		PRINTF("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%10"CNV"|", LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN);
//	}
//
//	TITLE("Another test\n");
//	{
//# define CNV "i"
//		printf("\n   |"CNV"|:\n");
//		PRINTF("|%5h h"CNV"|\t|%20l l"CNV"|", SHRT_MIN,LONG_MIN);
//		PRINTF("|%20l"CNV"|\t|%20ll"CNV"|\t|%20hh"CNV"|\t|%20h"CNV"|", -42,-42,-42,-42);
//	}
//	{
//# define CNV "d"
//		printf("\n   |"CNV"|:\n");
//		PRINTF("|%5h h"CNV"|\t|%20l l"CNV"|", SHRT_MIN,LONG_MIN);
//		PRINTF("|%20l"CNV"|\t|%20ll"CNV"|\t|%20hh"CNV"|\t|%20h"CNV"|", -42,-42,-42,-42);
//	}
//	{
//# define CNV "u"
//		printf("\n   |"CNV"|:\n");
//		PRINTF("|%5h h"CNV"|\t|%20l l"CNV"|", SHRT_MIN,LONG_MIN);
//		PRINTF("|%20l"CNV"|\t|%20ll"CNV"|\t|%20hh"CNV"|\t|%20h"CNV"|", -42,-42,-42,-42);
//	}
//	{
//# define CNV "x"
//		printf("\n   |"CNV"|:\n");
//		PRINTF("|%5h h"CNV"|\t|%20l l"CNV"|", SHRT_MIN,LONG_MIN);
//		PRINTF("|%20l"CNV"|\t|%20ll"CNV"|\t|%20hh"CNV"|\t|%20h"CNV"|", -42,-42,-42,-42);
//	}
//	{
//# define CNV "X"
//		printf("\n   |"CNV"|:\n");
//		PRINTF("|%5h h"CNV"|\t|%20l l"CNV"|", SHRT_MIN,LONG_MIN);
//		PRINTF("|%20l"CNV"|\t|%20ll"CNV"|\t|%20hh"CNV"|\t|%20h"CNV"|", -42,-42,-42,-42);
//	}
//	{
//# define CNV "o"
//		printf("\n   |"CNV"|:\n");
//		PRINTF("|%5h h"CNV"|\t|%20l l"CNV"|", SHRT_MIN,LONG_MIN);
//		PRINTF("|%20l"CNV"|\t|%20ll"CNV"|\t|%20hh"CNV"|\t|%20h"CNV"|", -42,-42,-42,-42);
//	}
//	TITLE("Very big number options(field width and length modifiers):\n");
//	PRINTF("|%22lld|\t|%22hhd|", -9223372036854775808,-9223372036854775808);
//	PRINTF("|%22llu|\t|%22hhu|", -9223372036854775808,-9223372036854775808);
//	PRINTF("|%22llo|\t|%22hho|", -9223372036854775808,-9223372036854775808);
//	PRINTF("|%22llx|\t|%22llX|\t|%22hhx|\t|%22hhX|", -9223372036854775808,-9223372036854775808,-9223372036854775808,-9223372036854775808);
////Not number options
//	TITLE("Not number number options(field width and length modifiers):");
//	{
//# define CNV "i"
//		printf("\n   |"CNV"|:\t|%20s|\t|%20s|\t|%20s|\t|%20s|\n", "l", "ll","hh", "h");
//		PRINTF("|%20l"CNV"|\t|%20ll"CNV"|\t|%20hh"CNV"|\t|%20h"CNV"|", "4294967296","4294967296","4294967296","4294967296");
//	}
//	{
//# define CNV "d"
//		printf("\n   |"CNV"|:\t|%20s|\t|%20s|\t|%20s|\t|%20s|\n", "l", "ll","hh", "h");
//		PRINTF("|%20l"CNV"|\t|%20ll"CNV"|\t|%20hh"CNV"|\t|%20h"CNV"|", "4294967296","4294967296","4294967296","4294967296");
//	}
//	{
//# define CNV "u"
//		printf("\n   |"CNV"|:\t|%20s|\t|%20s|\t|%20s|\t|%20s|\n", "l", "ll","hh", "h");
//		PRINTF("|%20l"CNV"|\t|%20ll"CNV"|\t|%20hh"CNV"|\t|%20h"CNV"|", "4294967296","4294967296","4294967296","4294967296");
//	}
//	{
//# define CNV "x"
//		printf("\n   |"CNV"|:\t|%20s|\t|%20s|\t|%20s|\t|%20s|\n", "l", "ll","hh", "h");
//		PRINTF("|%20l"CNV"|\t|%20ll"CNV"|\t|%20hh"CNV"|\t|%20h"CNV"|", "4294967296","4294967296","4294967296","4294967296");
//	}
//	{
//# define CNV "X"
//		printf("\n   |"CNV"|:\t|%20s|\t|%20s|\t|%20s|\t|%20s|\n", "l", "ll","hh", "h");
//		PRINTF("|%20l"CNV"|\t|%20ll"CNV"|\t|%20hh"CNV"|\t|%20h"CNV"|", "4294967296","4294967296","4294967296","4294967296");
//	}
//	{
//# define CNV "o"
//		printf("\n   |"CNV"|:\t|%20s|\t|%20s|\t|%20s|\t|%20s|\n", "l", "ll","hh", "h");
//		PRINTF("|%20l"CNV"|\t|%20ll"CNV"|\t|%20hh"CNV"|\t|%20h"CNV"|", "4294967296","4294967296","4294967296","4294967296");
//	}
//#endif
//
//
///*
//**	Put new stuff here like:
//
//#ifdef <test_name>
//	TITLE("<test name>\n");
//	PRINTF("test without \n in the end!");
//#endif
//
//*/
//
////Don't remove!
//	if (errno)
//		printf(RED"\n\n\tSome error has been found:\t%s\n"NORM, strerror(errno));
//
////LEAKS test (just make <gcc -D LEAKS> and it will work)
//#ifdef LEAKS
//	while (1) sleep(120);
//#endif
//	return (0);
//}


//
//int		main(void)
//{
//	printf("************************** Start Of Undefined Behaviour Tests: *********************************\n");
//	printf("1) \"%%\" -> \"\"\n");
//	ft_printf("mine:%\n");
//	printf("orig:%\n");
//	printf("2) \"%% \" -> \"\"\n");
//	ft_printf("mine:% \n");
//	printf("orig:% \n");
//	printf("3) \"%% h\" -> \"\"\n");
//	ft_printf("mine:% h\n");
//	printf("orig:% h\n");
//	printf("4) \"%%Z\" -> \"Z\"\n");
//	ft_printf("mine:%Z\n");
//	printf("orig:%Z\n");
//	printf("5) \"%% hZ\" -> \"Z\"\n");
//	ft_printf("mine:% hZ\n");
//	printf("orig:% hZ\n");
//	printf("6) \"%%05%%\" -> \"0000%\"\n");
//	ft_printf("mine:%05%\n");
//	printf("orig:%05%\n");
//	printf("7) \"%%-05%%\" -> \"%%    \"\n");
//	ft_printf("mine:%-05%\n");
//	printf("orig:%-05%\n");
//	printf("8) \"%% hZ\" -> \"Z\"\n");
//	ft_printf("mine:% hZ%\n");
//	printf("orig:% hZ%\n");
//	printf("9) \"%% Z%%\" -> \"Z\"\n");
//	ft_printf("mine:% Z%\n", "test");
//	printf("orig:% Z%\n", "test");
//	printf("10) \"%% Z \" -> \"Z \"\n");
//	ft_printf("mine:% Z \n", "test");
//	printf("orig:% Z \n", "test");
//	printf("11) \"%% Z%%s\\n\" -> \"Ztest\"\n");
//	ft_printf("mine:% Z%s\n", "test");
//	printf("orig:% Z%s\n", "test");
//	ft_printf("12) %000   %\n", "test\n");//                -> "%"
//	ft_printf("13) %%%\n", "test\n");//                     -> "%"
//	ft_printf("14) %%   %\n", "test\n"); //            -> "%   "
//	ft_printf("15) %ll#x\n", 9223372036854775807);//      -> "0x7fffffffffffffff"
//	ft_printf("16) %010s is a string\n", "this");//       -> "000000this is a string"
//	ft_printf("17) %-010s is a string\n", "this");//      -> "this       is a string"
//	ft_printf("18) %05c\n", 42);//                        -> "0000*"
//	ft_printf("19) % Z\n", 42);//                         -> "Z"
//	ft_printf("20) %0 d\n", 42);//                        -> " 42"
//	ft_printf("21) %0 d\n", -42);//                       -> "-42"
//	ft_printf("22) % 0d\n", 42);//                        -> " 42"
//	ft_printf("23) % 0d\n", -42);//                       -> "-42"
//	ft_printf("24) %5+d\n", 42);//                        -> "  +42"
//	ft_printf("25) %5+d\n", -42);//                       -> "  -42"
//	ft_printf("26) %-5+d\n", 42);//                       -> "+42  "
//	ft_printf("27) %-0+5d\n", 42);//                      -> "+42  "
//	ft_printf("28) %-5+d\n", -42);//                      -> "-42  "
//	ft_printf("29) %-0+5d\n", -42);//                     -> "-42  "
//	ft_printf("30) %zhd\n", 4294967296);//                -> "4294967296"
//	ft_printf("31) %jzd\n", 9223372036854775807);//       -> "9223372036854775807"
//	ft_printf("32) %jhd\n", 9223372036854775807);//       -> "9223372036854775807"
//	ft_printf("33) %lhl\n", 9223372036854775807);//       -> ""
//	ft_printf("34) %lhlz\n", 9223372036854775807);//      -> ""
//	ft_printf("35) %zj\n", 9223372036854775807);//        -> ""
//	ft_printf("36) %lhh\n", 2147483647);//                -> ""
//	ft_printf("37) %hhld\n", 128);//                      -> "128"
//	ft_printf("38) @main_ftprintf: %####0000 33..1..#00d\n", 256);
//	ft_printf("38) @main_ftprintf: %####0000 33..1..#00d\n", 256);// -> "@main_ftprintf:                               256$\n" оригинал выводит иначе
//	ft_printf("39) @main_ftprintf: %####0000 33..1d\n", 256);// -> "@main_ftprintf:                               256"
//	ft_printf("40) @main_ftprintf: %###-#0000 33...12..#0+0d\n", 256);// -> "@main_ftprintf: +256                             "
//	printf("*********************** End Of Undefined Behaviour Tests *****************************\n");
//
//	printf("orig:%#010.6o\n", 42);
//	ft_printf("mine:%#010.6o\n\n", 42);
//
//	printf("************************* X_TESTS: *****************************\n");
//	printf("%s\n", "1)");
//	printf("%x\n", 42);
//	ft_printf("%x\n\n", 42);
//	printf("%s\n", "2)");
//	printf("%x\n", -42);
//	ft_printf("%x\n\n", -42);
//	printf("%s\n", "3)");
//	printf("%#x\n", 42);
//	ft_printf("%#x\n\n", 42);
//	printf("%s\n", "4)");
//	printf("%10x\n", 42);
//	ft_printf("%10x\n\n", 42);
//	printf("%s\n", "5)");
//	printf("%10.x\n", 42);
//	ft_printf("%10.x\n\n", 42);
//	printf("%s\n", "6)");
//	printf("%10.0x\n", 42);
//	ft_printf("%10.0x\n\n", 42);
//	printf("%s\n", "7)");
//	printf("%10.2x\n", 42);
//	ft_printf("%10.2x\n\n", 42);
//	printf("%s\n", "8)");
//	printf("%10.4x\n", 42);
//	ft_printf("%10.4x\n\n", 42);
//	printf("%s\n", "9)");
//	printf("%10.11x\n", 42);
//	ft_printf("%10.11x\n\n", 42);
//	printf("%s\n", "10)");
//	printf("%#0x\n", 42);
//	ft_printf("%#0x\n\n", 42);
//	printf("%s\n", "11)");
//	printf("%#010x\n", 42);
//	ft_printf("%#010x\n\n", 42);
//	printf("%s\n", "12)");
//	printf("%#010.x\n", 42);
//	ft_printf("%#010.x\n", 42);
//	printf("%s\n", "13)");
//	printf("%#010.0x\n", 42);
//	ft_printf("%#010.0x\n\n", 42);
//	printf("%s\n", "14)");
//	printf("%#010.2x\n", 42);
//	ft_printf("%#010.2x\n\n", 42);
//	printf("%s\n", "15)");
//	printf("%#010.4x\n", 42);
//	ft_printf("%#010.4x\n\n", 42);
//	printf("%s\n", "16)");
//	printf("%#010.11x\n", 42);
//	ft_printf("%#010.11x\n\n", 42);
//	printf("%s\n", "17)");
//	printf("%#10x\n", 42);
//	ft_printf("%#10x\n\n", 42);
//	printf("%s\n", "18)");
//	printf("%#10.x\n", 42);
//	ft_printf("%#10.x\n\n", 42);
//	printf("%s\n", "19)");
//	printf("%#10.0x\n", 42);
//	ft_printf("%#10.0x\n\n", 42);
//	printf("%s\n", "20)");
//	printf("%#10.2x\n", 42);
//	ft_printf("%#10.2x\n\n", 42);
//	printf("%s\n", "21)");
//	printf("%#10.4x\n", 42);
//	ft_printf("%#10.4x\n\n", 42);
//	printf("%s\n", "22)");
//	printf("%#10.11x\n", 42);
//	ft_printf("%#10.11x\n\n", 42);
//	printf("%s\n", "23)");
//	printf("%#x\n", 42);
//	ft_printf("%#x\n\n", 42);
//	printf("%s\n", "24)");
//	printf("%10x\n", 42);
//	ft_printf("%10x\n\n", 42);
//	printf("%s\n", "25)");
//	printf("%10.x\n", 42);
//	ft_printf("%10.x\n\n", 42);
//	printf("%s\n", "26)");
//	printf("%10.0x\n", 42);
//	ft_printf("%10.0x\n\n", 42);
//	printf("%s\n", "27)");
//	printf("%10.2x\n", 42);
//	ft_printf("%10.2x\n\n", 42);
//	printf("%s\n", "28)");
//	printf("%10.4x\n", 42);
//	ft_printf("%10.4x\n\n", 42);
//	printf("%s\n", "29)");
//	printf("%10.11x\n", 42);
//	ft_printf("%10.11x\n\n", 42);
//	printf("%s\n", "30)");
//	printf("%#0x\n", 42);
//	ft_printf("%#0x\n\n", 42);
//	printf("%s\n", "31)");
//	printf("%#010x\n", 42);
//	ft_printf("%#010x\n\n", 42);
//	printf("%s\n", "32)");
//	printf("%#010.x\n", 42);
//	ft_printf("%#010.x\n\n", 42);
//	printf("%s\n", "33)");
//	printf("%#010.0x\n", 42);
//	ft_printf("%#010.0x\n\n", 42);
//	printf("%s\n", "34)");
//	printf("%#010.2x\n", 42);
//	ft_printf("%#010.2x\n\n", 42);
//	printf("%s\n", "35)");
//	printf("%#010.4x\n", 42);
//	ft_printf("%#010.4x\n\n", 42);
//	printf("%s\n", "36)");
//	printf("%#010.11x\n", 42);
//	ft_printf("%#010.11x\n\n", 42);
//	printf("%s\n", "37)");
//	printf("%#10x\n", 42);
//	ft_printf("%#10x\n\n", 42);
//	printf("%s\n", "38)");
//	printf("%#10.x\n", 42);
//	ft_printf("%#10.x\n\n", 42);
//	printf("%s\n", "39)");
//	printf("%#10.0x\n", 42);
//	ft_printf("%#10.0x\n\n", 42);
//	printf("%s\n", "40)");
//	printf("%#10.2x\n", 42);
//	ft_printf("%#10.2x\n\n", 42);
//	printf("%s\n", "41)");
//	printf("%#10.4x\n", 42);
//	ft_printf("%#10.4x\n\n", 42);
//	printf("%s\n", "42)");
//	printf("%#10.11x\n", 42);
//	ft_printf("%#10.11x\n\n", 42);
//	printf("%s\n", "43)");
//	printf("%-#x\n", 42);
//	ft_printf("%-#x\n\n", 42);
//	printf("%s\n", "44)");
//	printf("%-10x\n", 42);
//	ft_printf("%-10x\n\n", 42);
//	printf("%s\n", "45)");
//	printf("%-10.x\n", 42);
//	ft_printf("%-10.x\n\n", 42);
//	printf("%s\n", "46)");
//	printf("%-10.0x\n", 42);
//	ft_printf("%-10.0x\n\n", 42);
//	printf("%s\n", "47)");
//	printf("%-10.2x\n", 42);
//	ft_printf("%-10.2x\n\n", 42);
//	printf("%s\n", "48)");
//	printf("%-10.4x\n", 42);
//	ft_printf("%-10.4x\n\n", 42);
//	printf("%s\n", "49)");
//	printf("%-10.11x\n", 42);
//	ft_printf("%-10.11x\n\n", 42);
//	printf("%s\n", "50)");
//	printf("%-#0x\n", 42);
//	ft_printf("%-#0x\n\n", 42);
//	printf("%s\n", "51)");
//	printf("%-#010x\n", 42);
//	ft_printf("%-#010x\n\n", 42);
//	printf("%s\n", "52)");
//	printf("%-#010.x\n", 42);
//	ft_printf("%-#010.x\n\n", 42);
//	printf("%s\n", "53)");
//	printf("%-#010.0x\n", 42);
//	ft_printf("%-#010.0x\n\n", 42);
//	printf("%s\n", "54)");
//	printf("%-#010.2x\n", 42);
//	ft_printf("%-#010.2x\n\n", 42);
//	printf("%s\n", "55)");
//	printf("%-#010.4x\n", 42);
//	ft_printf("%-#010.4x\n\n", 42);
//	printf("%s\n", "56)");
//	printf("%-#010.11x\n", 42);
//	ft_printf("%-#010.11x\n\n", 42);
//	printf("%s\n", "57)");
//	printf("%-#10x\n", 42);
//	ft_printf("%-#10x\n\n", 42);
//	printf("%s\n", "58)");
//	printf("%-#10.x\n", 42);
//	ft_printf("%-#10.x\n\n", 42);
//	printf("%s\n", "59)");
//	printf("%-#10.0x\n", 42);
//	ft_printf("%-#10.0x\n\n", 42);
//	printf("%s\n", "60)");
//	printf("%-#10.2x\n", 42);
//	ft_printf("%-#10.2x\n\n", 42);
//	printf("%s\n", "61)");
//	printf("%-#10.4x\n", 42);
//	ft_printf("%-#10.4x\n\n", 42);
//	printf("%s\n", "62)");
//	printf("%-#10.11x\n", 42);
//	ft_printf("%-#10.11x\n\n", 42);
//	printf("**************** END OF X TESTS *******************\n\n\n");
//	printf("**************** D and I TESTS ********************\n");
//	printf("%s\n", "1)");
//	printf("%d\n", 42);
//	ft_printf("%d\n\n", 42);
//	printf("%s\n", "2)");
//	printf("%d\n", -42);
//	ft_printf("%d\n\n", -42);
//	printf("%s\n", "3)");
//	printf("%#d\n", 42);
//	ft_printf("%#d\n\n", 42);
//	printf("%s\n", "4)");
//	printf("%10d\n", 42);
//	ft_printf("%10d\n\n", 42);
//	printf("%s\n", "5)");
//	printf("%10.d\n", 42);
//	ft_printf("%10.d\n\n", 42);
//	printf("%s\n", "6)");
//	printf("%10.0d\n", 42);
//	ft_printf("%10.0d\n\n", 42);
//	printf("%s\n", "7)");
//	printf("%10.2d\n", 42);
//	ft_printf("%10.2d\n\n", 42);
//	printf("%s\n", "8)");
//	printf("%10.4d\n", 42);
//	ft_printf("%10.4d\n\n", 42);
//	printf("%s\n", "9)");
//	printf("%10.11d\n", 42);
//	ft_printf("%10.11d\n\n", 42);
//	printf("%s\n", "10)");
//	printf("%+0d\n", 42);
//	ft_printf("%+0d\n\n", 42);
//	printf("%s\n", "11)");
//	printf("%+010d\n", 42);
//	ft_printf("%+010d\n\n", 42);
//	printf("%s\n", "12)");
//	printf("%+010.d\n", 42);
//	ft_printf("%+010.d\n\n", 42);
//	printf("%s\n", "13)");
//	printf("%+010.0d\n", 42);
//	ft_printf("%+010.0d\n\n", 42);
//	printf("%s\n", "14)");
//	printf("%+010.2d\n", 42);
//	ft_printf("%+010.2d\n\n", 42);
//	printf("%s\n", "15)");
//	printf("%+010.4d\n", 42);
//	ft_printf("%+010.4d\n\n", 42);
//	printf("%s\n", "16)");
//	printf("%+010.11d\n", 42);
//	ft_printf("%+010.11d\n\n", 42);
//	printf("%s\n", "17)");
//	printf("%+10d\n", 42);
//	ft_printf("%+10d\n\n", 42);
//	printf("%s\n", "18)");
//	printf("%+10.d\n", 42);
//	ft_printf("%+10.d\n\n", 42);
//	printf("%s\n", "19)");
//	printf("%+10.0d\n", 42);
//	ft_printf("%+10.0d\n\n", 42);
//	printf("%s\n", "20)");
//	printf("%+10.2d\n", 42);
//	ft_printf("%+10.2d\n\n", 42);
//	printf("%s\n", "21)");
//	printf("%+10.4d\n", 42);
//	ft_printf("%+10.4d\n\n", 42);
//	printf("%s\n", "22)");
//	printf("%+10.11d\n", 42);
//	ft_printf("%+10.11d\n\n", 42);
//	printf("%s\n", "23)");
//	printf("%+d\n", 42);
//	ft_printf("%+d\n\n", 42);
//	printf("%s\n", "24)");
//	printf("%10d\n", 42);
//	ft_printf("%10d\n\n", 42);
//	printf("%s\n", "25)");
//	printf("%10.d\n", 42);
//	ft_printf("%10.d\n\n", 42);
//	printf("%s\n", "26)");
//	printf("%10.0d\n", 42);
//	ft_printf("%10.0d\n\n", 42);
//	printf("%s\n", "27)");
//	printf("%10.2d\n", 42);
//	ft_printf("%10.2d\n\n", 42);
//	printf("%s\n", "28)");
//	printf("%10.4d\n", 42);
//	ft_printf("%10.4d\n\n", 42);
//	printf("%s\n", "29)");
//	printf("%10.11d\n", 42);
//	ft_printf("%10.11d\n\n", 42);
//	printf("%s\n", "30)");
//	printf("%+0d\n", 42);
//	ft_printf("%+0d\n\n", 42);
//	printf("%s\n", "31)");
//	printf("%+010d\n", 42);
//	ft_printf("%+010d\n\n", 42);
//	printf("%s\n", "32)");
//	printf("%+010.d\n", 42);
//	ft_printf("%+010.d\n\n", 42);
//	printf("%s\n", "33)");
//	printf("%+010.0d\n", 42);
//	ft_printf("%+010.0d\n\n", 42);
//	printf("%s\n", "34)");
//	printf("%+010.2d\n", 42);
//	ft_printf("%+010.2d\n\n", 42);
//	printf("%s\n", "35)");
//	printf("%+010.4d\n", 42);
//	ft_printf("%+010.4d\n\n", 42);
//	printf("%s\n", "36)");
//	printf("%+010.11d\n", 42);
//	ft_printf("%+010.11d\n\n", 42);
//	printf("%s\n", "37)");
//	printf("%+10d\n", 42);
//	ft_printf("%+10d\n\n", 42);
//	printf("%s\n", "38)");
//	printf("%+10.d\n", 42);
//	ft_printf("%+10.d\n\n", 42);
//	printf("%s\n", "39)");
//	printf("%+10.0d\n", 42);
//	ft_printf("%+10.0d\n\n", 42);
//	printf("%s\n", "40)");
//	printf("%+10.2d\n", 42);
//	ft_printf("%+10.2d\n\n", 42);
//	printf("%s\n", "41)");
//	printf("%+10.4d\n", 42);
//	ft_printf("%+10.4d\n\n", 42);
//	printf("%s\n", "42)");
//	printf("%+10.11d\n", 42);
//	ft_printf("%+10.11d\n\n", 42);
//	printf("%s\n", "43)");
//	printf("%-+d\n", 42);
//	ft_printf("%-+d\n\n", 42);
//	printf("%s\n", "44)");
//	printf("%-10d\n", 42);
//	ft_printf("%-10d\n\n", 42);
//	printf("%s\n", "45)");
//	printf("%-10.d\n", 42);
//	ft_printf("%-10.d\n\n", 42);
//	printf("%s\n", "46)");
//	printf("%-10.0d\n", 42);
//	ft_printf("%-10.0d\n\n", 42);
//	printf("%s\n", "47)");
//	printf("%-10.2d\n", 42);
//	ft_printf("%-10.2d\n\n", 42);
//	printf("%s\n", "48)");
//	printf("%-10.4d\n", 42);
//	ft_printf("%-10.4d\n\n", 42);
//	printf("%s\n", "49)");
//	printf("%-10.11d\n", 42);
//	ft_printf("%-10.11d\n\n", 42);
//	printf("%s\n", "50)");
//	printf("%-+0d\n", 42);
//	ft_printf("%-+0d\n\n", 42);
//	printf("%s\n", "51)");
//	printf("%-+010d\n", 42);
//	ft_printf("%-+010d\n\n", 42);
//	printf("%s\n", "52)");
//	printf("%-+010.d\n", 42);
//	ft_printf("%-+010.d\n\n", 42);
//	printf("%s\n", "53)");
//	printf("%-+010.0d\n", 42);
//	ft_printf("%-+010.0d\n\n", 42);
//	printf("%s\n", "54)");
//	printf("%-+010.2d\n", 42);
//	ft_printf("%-+010.2d\n\n", 42);
//	printf("%s\n", "55)");
//	printf("%-+010.4d\n", 42);
//	ft_printf("%-+010.4d\n\n", 42);
//	printf("%s\n", "56)");
//	printf("%-+010.11d\n", 42);
//	ft_printf("%-+010.11d\n\n", 42);
//	printf("%s\n", "57)");
//	printf("%-+10d\n", 42);
//	ft_printf("%-+10d\n\n", 42);
//	printf("%s\n", "58)");
//	printf("%-+10.d\n", 42);
//	ft_printf("%-+10.d\n\n", 42);
//	printf("%s\n", "59)");
//	printf("%-+10.0d\n", 42);
//	ft_printf("%-+10.0d\n\n", 42);
//	printf("%s\n", "60)");
//	printf("%-+10.2d\n", 42);
//	ft_printf("%-+10.2d\n\n", 42);
//	printf("%s\n", "61)");
//	printf("%-+10.4d\n", 42);
//	ft_printf("%-+10.4d\n\n", 42);
//	printf("%s\n", "62)");
//	printf("%-+10.11d\n", 42);
//	ft_printf("%-+10.11d\n\n", 42);
//	printf("%s\n", "63)");
//	printf("%-+10.11d\n", 42);
//	ft_printf("%-+10.11d\n\n", 42);
//	printf("%s\n", "64)");
//	printf("%+d\n", 42);
//	ft_printf("%+d\n\n", 42);
//	printf("%s\n", "65)");
//	printf("%-+d\n", 42);
//	ft_printf("%-+d\n\n", 42);
//	printf("%s\n", "66)");
//	printf("% d\n", 42);
//	ft_printf("% d\n\n", 42);
//	printf("%s\n", "67)");
//	printf("%- d\n", 42);
//	ft_printf("%- d\n\n", 42);
//	printf("%s\n", "68)");
//	printf("% +d\n", 42);
//	ft_printf("% +d\n\n", 42);
//	printf("%s\n", "69)");
//	printf("%- +d\n", 42);
//	ft_printf("%- +d\n\n", 42);
//	printf("%d\n", 42);
//	ft_printf("%d\n", 42);
//	printf("%d\n", -42);
//	ft_printf("%d\n", -42);
//	printf("% d\n", 42);
//	ft_printf("% d\n", 42);
//	printf("% d\n", -42);
//	ft_printf("% d\n", -42);
//	printf("% d\n", -42);
//	ft_printf("% d\n", -42);
//	printf("%+d\n", 42);
//	ft_printf("%+d\n", 42);
//	printf("%10d\n", 42);
//	ft_printf("%10d\n", 42);
//	printf("%10d\n", -42);
//	ft_printf("%10d\n", -42);
//	printf("%010d\n", 42);
//	ft_printf("%010d\n", 42);
//	printf("%010d\n", -42);
//	ft_printf("%010d\n", -42);
//	printf("% 010d\n", 402);
//	ft_printf("% 010d\n", 402);
//	printf("%10.d\n", 42);
//	ft_printf("%10.d\n", 42);
//	printf("% 010.d\n", 42);
//	ft_printf("% 010.d\n", 42);
//	printf("% 010.0d\n", 42);
//	ft_printf("% 010.0d\n", 42);
//	printf("% 010.1d\n", 42);
//	ft_printf("% 010.1d\n", 42);
//	printf("% 010.2d\n", 42);
//	ft_printf("% 010.2d\n", 42);
//	printf("% 010.3d\n", 42);
//	ft_printf("% 010.3d\n", 42);
//	printf("% 010.4d\n", -42);
//	ft_printf("% 010.4d\n", -42);
//	printf("**************** END OF D and I TESTS ********************\n\n\n");
//	int i = 0;
//	int j = 0;
//	i = printf("%10000.10s\n", "Hello");
//	j = ft_printf("%10000.10s\n", "Hello");
//	printf("%i\n", i);
//	printf("%i\n", j);
//
//	printf("%10.1f\n", 42.42);
//	ft_printf("%f\n", -42.4242);
//	printf("orig:\"@moulitest: %+05.0d\"\n", 1);
//	ft_printf("mine:\"@moulitest: %+05.0d\"\n", 1);
//	printf("{%5.ZZ}\n", 0);
//	ft_printf("{%5.ZZ}\n", 0);
//
//	printf("@moulitest: %#.o %#.0o\n", 0, 0);
//	ft_printf("@moulitest: %#.o %#.0o\n\n", 0, 0);
//
////	printf("%llo, %llo\n", 0, USHRT_MAX);
////	ft_printf("%llo, %llo\n\n", 0, USHRT_MAX);
//
//	printf("%ju\n", 4294967296);
//	ft_printf("%ju\n\n", 4294967296);
//
//	printf("%+d\n", 0);
//	ft_printf("%+d\n\n", 0);
//
//	printf("%15u\n", 4294967295);
//	ft_printf("%15u\n\n", 4294967295);
//
//	printf("%c\n", NULL);
//	ft_printf("%c\n\n", NULL);
//
////	printf("********************* NULL TESTS *******************************\n");
////
////	printf("1)\n");
////	i = printf("orig:\"%d\"\n", 0);
////	j = ft_printf("mine:\"%d\"\n", 0);
////	printf("orig:%i\nmine:%i\n\n", i , j);
////
////	printf("2)\n");
////	i = printf("orig:\"%.d\"\n", 0);
////	j = ft_printf("mine:\"%.d\"\n", 0);
////	printf("orig:%i\nmine:%i\n\n", i , j);
////
////	printf("3)\n");
////	i = printf("orig:\"%.0d\"\n", 0);
////	j = ft_printf("mine:\"%.0d\"\n", 0);
////	printf("orig:%i\nmine:%i\n\n", i , j);
////
////	printf("4)\n");
////	i = printf("orig:\"%10d\"\n", 0);
////	j = ft_printf("mine:\"%10d\"\n", 0);
////	printf("orig:%i\nmine:%i\n\n", i , j);
////
////	printf("5)\n");
////	i = printf("orig:\"%10.d\"\n", 0);
////	j = ft_printf("mine:\"%10.d\"\n", 0);
////	printf("orig:%i\nmine:%i\n\n", i , j);
////
////	printf("6)\n");
////	i = printf("orig:\"%-10.d\"\n", 0);
////	j = ft_printf("mine:\"%-10.d\"\n", 0);
////	printf("orig:%i\nmine:%i\n\n", i , j);
////
////	printf("7)\n");
////	i = printf("orig:\"%-.d\"\n", 0);
////	j = ft_printf("mine:\"%-.d\"\n", 0);
////	printf("orig:%i\nmine:%i\n\n", i , j);
////
////	printf("8)\n");
////	i = printf("orig:\"%-10.d\"\n", 0);
////	j = ft_printf("mine:\"%-10.d\"\n", 0);
////	printf("orig:%i\nmine:%i\n\n", i , j);
////
////	printf("9)\n");
////	i = printf("orig:\"%10.d\"\n", 0);
////	j = ft_printf("mine:\"%10.d\"\n", 0);
////	printf("orig:%i\nmine:%i\n\n", i , j);
////
////	printf("9)\n");
////	i = printf("orig:\"%10.2d\"\n", 0);
////	j = ft_printf("mine:\"%10.2d\"\n", 0);
////	printf("orig:%i\nmine:%i\n\n", i , j);
////
////	printf("10)\n");
////	i = printf("orig:\"%-10.2d\"\n", 0);
////	j = ft_printf("mine:\"%-10.2d\"\n", 0);
////	printf("orig:%i\nmine:%i\n\n", i , j);
////
////	printf("11)\n");
////	i = printf("orig:\"%0.d\"\n", 0);
////	j = ft_printf("mine:\"%0.d\"\n", 0);
////	printf("orig:%i\nmine:%i\n\n", i , j);
////
////	printf("12)\n");
////	i = printf("orig:\"%x\"\n", 0);
////	j = ft_printf("mine:\"%x\"\n", 0);
////	printf("orig:%i\nmine:%i\n\n", i , j);
////
////	printf("13)\n");
////	i = printf("orig:\"%.x\"\n", 0);
////	j = ft_printf("mine:\"%.x\"\n", 0);
////	printf("orig:%i\nmine:%i\n\n", i , j);
////
////	printf("14)\n");
////	i = printf("orig:\"%.0x\"\n", 0);
////	j = ft_printf("mine:\"%.0x\"\n", 0);
////	printf("orig:%i\nmine:%i\n\n", i , j);
////
////	printf("15)\n");
////	i = printf("orig:\"%x\"\n", 0);
////	j = ft_printf("mine:\"%x\"\n", 0);
////	printf("orig:%i\nmine:%i\n\n", i , j);
////
////	printf("16)\n");
////	i = printf("orig:\"%10.x\"\n", 0);
////	j = ft_printf("mine:\"%10.x\"\n", 0);
////	printf("orig:%i\nmine:%i\n\n", i , j);
////
////	printf("17)\n");
////	i = printf("orig:\"%-10.x\"\n", 0);
////	j = ft_printf("mine:\"%-10.x\"\n", 0);
////	printf("orig:%i\nmine:%i\n\n", i , j);
////
////	printf("18)\n");
////	i = printf("orig:\"%-.x\"\n", 0);
////	j = ft_printf("mine:\"%-.x\"\n", 0);
////	printf("orig:%i\nmine:%i\n\n", i , j);
////
////	printf("19)\n");
////	i = printf("orig:\"%-10.x\"\n", 0);
////	j = ft_printf("mine:\"%-10.x\"\n", 0);
////	printf("orig:%i\nmine:%i\n\n", i , j);
////
////	printf("20)\n");
////	i = printf("orig:\"%10.x\"\n", 0);
////	j = ft_printf("mine:\"%10.x\"\n", 0);
////	printf("orig:%i\nmine:%i\n\n", i , j);
////
////	printf("21)\n");
////	i = printf("orig:\"%10.2x\"\n", 0);
////	j = ft_printf("mine:\"%10.2x\"\n", 0);
////	printf("orig:%i\nmine:%i\n\n", i , j);
////
////	printf("22)\n");
////	i = printf("orig:\"%-10.2x\"\n", 0);
////	j = ft_printf("mine:\"%-10.2x\"\n", 0);
////	printf("orig:%i\nmine:%i\n\n", i , j);
////
////	printf("23)\n");
////	i = printf("orig:\"%0.x\"\n", 0);
////	j = ft_printf("mine:\"%0.x\"\n", 0);
////	printf("orig:%i\nmine:%i\n\n", i , j);
////
////	printf("%o\n", 0);
////	ft_printf("%o\n\n", 0);
////
////	printf("%#o\n", 0);
////	ft_printf("%#o\n\n", 0);
////
////	printf("%#10.o\n", 0);
////	ft_printf("%#10.o\n\n", 0);
////
////	printf("%#10o\n", 0);
////	ft_printf("%#10o\n\n", 0);
////
////	printf("%#-10o\n", 0);
////	ft_printf("%#-10o\n\n", 0);
////
////	printf("@moulitest: %.o %.0o\n", 0, 0);
////	ft_printf("@moulitest: %.o %.0o\n\n", 0, 0);
////
////	printf("{%*%}\n", -15);
////	ft_printf("{%*%}\n\n", -15);
////
////	printf("{%*d}\n", -5, 42);
////	ft_printf("{%*d}\n\n", -5, 42);
////
////	printf("{%.*s}\n", -5, "42");
////	ft_printf("{%.*s}\n\n", -5, "42");
////
////	printf("%*d\n", 5, 42);
////	ft_printf("%*d\n", 5, 42);
////
////	printf("{%*.3s}\n", 3, "Hello");
////	ft_printf("{%*.3s}\n", 3, "Hello");
////
////	printf("@moulitest: %#.x %#.0x\n", 0, 0);
////	ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
////
////	printf("\n%#-30x\n", 40);
////	ft_printf("%#-30x\n\n", 40);
//
//	printf("* ************** END OF NULL TESTS ************************* *\n\n\n");
//	printf("* **************** FLOAT TESTS ***************************** *\n");
//
//	printf("1)\n{%.19f}\n", 0.0004242);
//	ft_printf("{%.19f}\n\n", 0.0004242);
//
//	printf("2)\n{%.50f}\n", 42.42424242);
//	ft_printf("{%.50f}\n\n", 42.42424242);
//
//	printf("3)\n{%f}\n", 42.424242);
//	ft_printf("{%f}\n\n", 42.424242);
//
//	printf("4)\n{%.f}\n", 42.42);
//	ft_printf("{%.f}\n\n", 42.42);
//
//	printf("5)\n{%.0f}\n", 42.42);
//	ft_printf("{%.0f}\n\n", 42.42);
//
//	printf("6)\n{%.2f}\n", 42.42);
//	ft_printf("{%.2f}\n\n", 42.42);
//
//	printf("7)\n{%.3f}\n", 42.42);
//	ft_printf("{%.3f}\n\n", 42.42);
//
//	printf("8)\n{%.10f}\n", 42.42);
//	ft_printf("{%.10f}\n\n", 42.42);
//
//	printf("9)\n{%.20f}\n", 42.42);
//	ft_printf("{%.20f}\n\n", 42.42);
//
//	printf("9.1)\n{%.200f}\n", 42.42);
//	ft_printf("{%.200f}\n\n", 42.42);
//
//	printf("9.2)\n{%.2000f}\n", 42.42);
//	ft_printf("{%.2000f}\n\n", 42.42);
//
//	printf("9.3)\n{%.20000f}\n", 42.42);
//	printf("{%.20000f}\n\n", 42.42);
//
//	printf("10)\n{%15f}\n", 42.42);
//	ft_printf("{%15f}\n\n", 42.42);
//
//	printf("11)\n{%15f}\n", -42.42);
//	ft_printf("{%15f}\n\n", -42.42);
//
//	printf("12)\n{%-15f}\n", -0.0);
//	ft_printf("{%-15f}\n\n", -0.0);
//
//	printf("13)\n{%15f}\n", 0.0);
//	ft_printf("{%15f}\n\n", 0.0);
//
//	printf("14)\n{%20f}\n", 42.42);
//	ft_printf("{%20f}\n\n", 42.42);
//
//	printf("15)\n{%20.f}\n", 42.42);
//	ft_printf("{%20.f}\n\n", 42.42);
//
//	printf("16)\n{%20.0f}\n", 42.42);
//	ft_printf("{%20.0f}\n\n", 42.42);
//
//	printf("17)\n{%020.0f}\n", 42.42);
//	ft_printf("{%020.0f}\n\n", 42.42);
//
//	printf("18)\n{% 020.0f}\n", 42.42);
//	ft_printf("{% 020.0f}\n\n", 42.42);
//
//	printf("19)\n{%020.0f}\n", -42.42);
//	ft_printf("{%020.0f}\n\n", -42.42);
//
//	printf("20)\n{%-20.0f}\n", 42.42);
//	ft_printf("{%-20.0f}\n\n", 42.42);
//
//	printf("21)\n{%-20.0f}\n", 42.42);
//	ft_printf("{%-20.0f}\n\n", 42.42);
//
//	printf("22)\n{%-20.1f}\n", 42.42);
//	ft_printf("{%-20.1f}\n\n", 42.42);
//
//	printf("23)\n{%-20f}\n", 42.42);
//	ft_printf("{%-20f}\n\n", 42.42);
//
//	printf("24\n{%+20.f}\n", 42.42);
//	ft_printf("{%+20.f}\n\n", 42.42);
//
//	printf("25\n{%-+20.f}\n", 42.42);
//	ft_printf("{%-+20.f}\n\n", 42.42);
//
//	printf("26)\n{%-+20.f}\n", -42.42);
//	ft_printf("{%-+20.f}\n\n", -42.42);
//
//	printf("27)\n{%-+20.200f}\n", -42.42);
//	ft_printf("{%-+20.200f}\n\n", -42.42);
//
//	printf("28)\n{%+20.200f}\n", -42.42);
//	ft_printf("{%+20.200f}\n\n", -42.42);
//
//	printf("29)\n{%10f}\n", -42.42);
//	ft_printf("{%10f}\n\n", -42.42);
//
//	printf("30)\n{%.f}\n", 3.5);
//	ft_printf("{%.f}\n\n", 3.5);
//
//	printf("31)\n{%.f}\n", 3.2);
//	ft_printf("{%.f}\n\n", 3.2);
//
//	printf("32)\n{%.1f}\n", 3.22);
//	ft_printf("{%.1f}\n\n", 3.22);
//
//	printf("33)\n{%.1f}\n", 3.27);
//	ft_printf("{%.1f}\n\n", 3.27);
//
//	printf("34)\n{%.1f}\n", 3.25);
//	ft_printf("{%.1f}\n\n", 3.25);
//
//	printf("35)\n{%.f}\n", 2.5);
//	ft_printf("{%.f}\n\n", 2.5);
//
//	printf("36)\n{%.7f}\n", 99.999);
//	ft_printf("{%.7f}\n\n", 99.999);
//
//	printf("37)\n{%.7f}\n", 99.9999999);
//	ft_printf("{%.7f}\n\n", 99.9999999);
//
//	printf("38)\n{%.7f}\n", 99.99999999);
//	ft_printf("{%.7f}\n\n", 99.99999999);
//
//	printf("39)\n{%.7f}\n", 99.99999999999);
//	ft_printf("{%.7f}\n\n", 99.99999999999);
//
//	printf("40)\n{%#.f}\n", 99.9);
//	ft_printf("{%#.f}\n\n", 99.9);
//
//	printf("40.1)\n{%#.f}\n", 98.9);
//	ft_printf("{%#.f}\n\n", 98.9);
//
//	printf("41)\n{%.f}\n", 99.5);
//	ft_printf("{%.f}\n\n", 99.5);
//
//	printf("41.1)\n{%.f}\n", 98.5);
//	ft_printf("{%.f}\n\n", 98.5);
//
//	printf("42)\n{%.Lf}\n", 9999999999999999999.9l);
//	ft_printf("{%.Lf}\n\n", 9999999999999999999.9l);
//	// округление в большую сторону идет только по нечетным числам,
//	// в меньшую по четным (примеры ниже)
//	printf("43)\n{%.f}\n", 2.5);
//	ft_printf("{%.f}\n\n", 2.5);
//
//	printf("44)\n{%.f}\n", 3.5);
//	ft_printf("{%.f}\n\n", 3.5);
//
//	printf("45)\n{%.2f}\n", 3.559);
//	ft_printf("{%.2f}\n\n", 3.559);
//
//	printf("46)\n{%.3f}\n", 3.559);
//	ft_printf("{%.3f}\n\n", 3.559);
//
//	printf("47)\n{%.2f}\n", 3.59999999);
//	ft_printf("{%.2f}\n\n", 3.59999999);
//
//	printf("48)\n{%.2f}\n", 3.55111111);
//	ft_printf("{%.2f}\n\n", 3.55111111);
//
//	printf("49)\n{%f}\n", 0.0/0.0);
//	ft_printf("{%f}\n\n", 0.0/0.0);
//
//	printf("50)\n{%f}\n", 3.0/0.0);
//	ft_printf("{%f}\n\n", 3.0/0.0);
//
//	printf("51)\n{%f}\n", -3.0/0.0);
//	ft_printf("{%f}\n\n", -3.0/0.0);
//
////	printf("* ****************************** BONUSES ****************************** *\n");
////
////	printf("52)\n{%F}\n", -3.0/0.0);
////	ft_printf("{%F}\n\n", -3.0/0.0);
////
////	printf("53)\n{%F}\n", 3.0/0.0);
////	ft_printf("{%F}\n\n", 3.0/0.0);
////
////	printf("54)\n{%F}\n", 0.0/0.0);
////	ft_printf("{%F}\n\n", 0.0/0.0);
////
////	ft_printf("{%r}\n", "hello\n again\t!");
////	ft_printf("vitya---> %r\n", "Hello my\n guests");
////	ft_printf("{% 10b}\n\n", 23534523452);
////
////	int counter;
////	counter = ft_printf("{red}%s{eoc}{green} And this is green!\n{eoc}And where the Fuck have you all been?\n{cyan}Do you know - this color's \"Cyan\"?\n{eoc}{yellow}Checking yellow!{eoc} {blue}Blue is fine!{eoc}\n{purple}And purple's nice!{eoc} That's it - I'm done!\n", "This color's red!");
////	printf("%i\n", counter);
////	printf("{%f}{%F}\n", 1.42, 1.42);
////	ft_printf("{%f}{%F}\n\n", 1.42, 1.42);
////
////	printf("{%f}{%F}\n", -1.42, -1.42);
////	ft_printf("{%f}{%F}\n\n", -1.42, -1.42);
////
////	printf("{%f}{%F}\n", 1444565444646.6465424242242, 1444565444646.6465424242242);
////	ft_printf("{%f}{%F}\n\n", 1444565444646.6465424242242, 1444565444646.6465424242242);
////
////	printf("{%f}{%F}\n", -1444565444646.6465424242242454654, -1444565444646.6465424242242454654);
////	ft_printf("{%f}{%F}\n", -1444565444646.6465424242242454654, -1444565444646.6465424242242454654);
////
////	ft_printf("1mo{%o}\n", 40);printf("1oo{%o}\n", 40);
////	ft_printf("2m5o{%5o}\n", 41);printf("2o5o{%5o}\n", 41);
////	ft_printf("3m{%05o}\n", 42);printf("3o{%05o}\n", 42);
////	ft_printf("4m{%-5o}\n", 2500);printf("4o{%-5o}\n", 2500);
////	ft_printf("5m{%#6o}\n", 2500);printf("5o{%#6o}\n", 2500);
////	ft_printf("6m{%-#6o}\n", 2500); printf("6o{%-#6o}\n", 2500);
////	ft_printf("7m{%-05o}\n", 2500);printf("7o{%-05o}\n", 2500);
////	ft_printf("8m{%-5.10o}\n", 2500); printf("8o{%-5.10o}\n", 2500);
////	ft_printf("9m{%-10.5o}\n", 2500); printf("9o{%-10.5o}\n", 2500);
////	//ft_printf("%hU", 4294967296);
//
//	system("leaks -q ft_printf");
//	return (0);
//}
